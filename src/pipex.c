/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:18:40 by jroseiro          #+#    #+#             */
/*   Updated: 2024/08/29 12:55:09 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void run (char *cmd, char **env)
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
		exit(127); // 127 is the standard exit code for command not found
	}
}



void child_in(char **argv, int *pipefd, char **env)
{
	int fd;

	fd = open_f(argv[1], 0);
	dup2(fd, STDIN_FILENO);	// redirect standard input to file descriptor
	dup2(pipefd[1], 1);	//redirect standard output to write end of the pipe
	close(pipefd[0]);	// close the read end of the pipe
	close(fd);
	run(argv[2], env);	// exe command, aka 3rd (2nd counting from 0) argument inputed in main
}



void child_out(char **argv, int *pipefd, char **env)
{
	int fd;

	fd = open_f(argv[4], 1);
	dup2(fd, STDOUT_FILENO);
	dup2(pipefd[0], 0);
	close(pipefd[1]);
	close(fd);
	run(argv[3], env);	// all this is is basically the oposite of the child's actions
}


int main(int argc, char **argv, char **env)
{
	int pipefd[2]; // creating two 'processes' bcs 2 FDs
	pid_t cpid[2]; // child process ID
	int status;

	if (argc !=5) // if it has more than 5 arguments, something is wrong, error handling
		mayday(1);// emergency exit 🚨🚨🚨🚨
	if (pipe(pipefd) == -1) // if the fd is -1 there is an error and we need to exit with correct error handling
		exit (EXIT_FAILURE);
	cpid[0] = fork(); // forking the child processes
	if (cpid[0] == 0)
		child_in(argv, pipefd, env);
	else
	{
		cpid[1] = fork();
		if (cpid[1] == 0)
			child_out(argv, pipefd, env); // we need to open the file, dup2 it, 
		close(pipefd[0]);
		close(pipefd[1]);
		waitpid(cpid[0], &status, 0);
		waitpid(cpid[1], &status, 0);
		if (WIFEXITED(status))
			exit(WEXITSTATUS(status));
	}
	return (0);
}

/*
	// creating two pipes from the pipefd[2] 
	// (bcs the two means its using two file descriptors, one for writting one for reading)
	pipe(pipefd);
	// Forking the processes
	cpid = fork();

	// setting up the file descriptors
		// FOR COMMAND 1
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);
		// FOR COMMAND 2
	dup2(pipefd[0], STDOUT_FILENO);
	close(pipefd[0]);
	execlp("command1", "command1", (char *) NULL);
	execlp("command2", "command2", (char *) NULL);

	close(pipefd[0]);
	close(pipefd[1]);






 execve (execute with vector of environment variables) is what
  allows the shell the execute a command.
  Everytime we write a command in the terminal, execve() is run,
  which then takes up the task of executing the command that one
  types in the terminal.

  envp is an array of pointers to strings, conventionally of the
  form key=value, which are passed as the environment of the new
  program.  The envp array must be terminated by a null pointer.
*/
