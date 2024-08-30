/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:18:40 by jroseiro          #+#    #+#             */
/*   Updated: 2024/08/30 10:52:17 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	run(char *cmd, char **env)
{
	char	**s_cmd;
	char	*path;

	s_cmd = ft_split(cmd, ' ');
	path = get_path(s_cmd[0], env);
	if (execve(path, s_cmd, env) == -1)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(s_cmd[0], 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(errno), 2);
		usa(s_cmd);
		free(path);
		exit(127);
	}
}

void	child_in(char **argv, int *pipefd, char **env)
{
	int	fd;

	fd = open_f(argv[1], 0);
	dup2(fd, STDIN_FILENO);
	dup2(pipefd[1], 1);
	close(pipefd[0]);
	close(fd);
	run(argv[2], env);
}

void	child_out(char **argv, int *pipefd, char **env)
{
	int	fd;

	fd = open_f(argv[4], 1);
	dup2(fd, STDOUT_FILENO);
	dup2(pipefd[0], 0);
	close(pipefd[1]);
	close(fd);
	run(argv[3], env);
}

int	main(int argc, char **argv, char **env)
{
	int		pipefd[2];
	pid_t	cpid[2];
	int		status;

	if (argc != 5)
		mayday(1);
	if (pipe(pipefd) == -1)
		exit (EXIT_FAILURE);
	cpid[0] = fork();
	if (cpid[0] == 0)
		child_in(argv, pipefd, env);
	else
	{
		cpid[1] = fork();
		if (cpid[1] == 0)
			child_out(argv, pipefd, env);
		close(pipefd[0]);
		close(pipefd[1]);
		waitpid(cpid[0], &status, 0);
		waitpid(cpid[1], &status, 0);
		if (WIFEXITED(status))
			exit(WEXITSTATUS(status));
	}
	return (0);
}
