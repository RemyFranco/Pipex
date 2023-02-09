/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfranco <rfranco@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:56:16 by rfranco           #+#    #+#             */
/*   Updated: 2023/02/07 17:11:32 by rfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"

# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>

typedef struct s_pipex
{
	int		num_cmds;
	int		in_fd;
	int		out_fd;
	int		pipe_fd[2];
	char	**paths;
	char	***cmds;
	pid_t	pid1;
	pid_t	pid2;
}			t_pipex;

// main.c
void	exit_argc(void);
void	exit_error(char *msg);
void	free_cmds(char ***cmds);
void	close_and_free(t_pipex ppx);

// args_parsing.c
void	args_parsing(t_pipex *ppx, int argc, char **argv, char **envp);
char	**get_paths(char **envp);
char	***get_cmds(int num_cmds, char **argv);

// ft_ppxsplit.c
char	**ft_ppxsplit(char *s);

// child.c
void	child_1(t_pipex ppx, char **envp);
void	child_2(t_pipex ppx, char **envp);

#endif