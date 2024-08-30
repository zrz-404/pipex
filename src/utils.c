/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:59:58 by jroseiro          #+#    #+#             */
/*   Updated: 2024/08/30 11:26:00 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	mayday(int e_code)
{
	if (e_code == 1)
		ft_putstr_fd("Usage: ./pipex infile cmd cmd outfile\n", 2);
	exit(e_code);
}

int	open_f(char *file, int in_or_out)
{
	int	ret;

	if (in_or_out == 0)
		ret = open(file, O_RDONLY);
	if (in_or_out == 1)
		ret = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (ret == -1)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(errno), 2);
		exit(ret);
	}
	return (ret);
}

// land of the 'frees', baby
void	usa(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

char	*ft_getenv(char *name, char **env)
{
	size_t	i;
	size_t	j;
	char	*sub;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		sub = ft_substr(env[i], 0, j);
		if (ft_strcmp(sub, name) == 0)
		{
			free(sub);
			return (env[i] + j + 1);
		}
		free(sub);
		i++;
	}
	return (NULL);
}

char	*get_path(char *cmd, char **env)
{
	size_t	i;
	char	*exec;
	char	**allpath;
	char	*path_sec;
	char	**s_cmd;

	i = -1;
	allpath = ft_split(ft_getenv("PATH", env), ':');
	s_cmd = ft_split(cmd, ' ');
	while (allpath[i++])
	{
		path_sec = ft_strjoin(allpath[i], "/");
		exec = ft_strjoin(path_sec, s_cmd[0]);
		free(path_sec);
		if (access(exec, F_OK | X_OK) == 0)
		{
			usa(s_cmd);
			usa(allpath);
			return (exec);
		}
		free(exec);
	}
	usa(allpath);
	usa(s_cmd);
	return (ft_strdup(cmd));
}
