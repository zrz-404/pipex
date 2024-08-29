/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:08:34 by jroseiro          #+#    #+#             */
/*   Updated: 2024/08/29 13:19:39 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include "./libft/libft.h"

int		open_f(char *file, int in_or_out);
char	*ft_getenv(char *name, char **env);
char	*get_path(char *cmd, char **env);
void	run(char *cmd, char **env);
void	usa(char **tab);
void	mayday(int e_code);

#endif