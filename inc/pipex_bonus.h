/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfranco <rfranco@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:54:36 by rfranco           #+#    #+#             */
/*   Updated: 2023/02/13 16:13:58 by rfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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
	int		num_pipes;
	int		num_pipe_fd;
	int		*pipe_fd;
	pid_t	*pid;
	char	**paths;
	char	***cmds;
}			t_pipex;

// main_bonus.c
void	exit_argc(void);
void	exit_error(char *msg);
void	free_cmds(char ***cmds);
void	free_all(t_pipex ppx);

// utils_bonus.c
void	open_pipes(t_pipex *ppx, int argc);
void	close_pipes(t_pipex ppx);
void	free_parent(t_pipex ppx);
void	wait_all_pid(t_pipex ppx, int *status);
void	close_all(t_pipex ppx);

// args_parsing_bonus.c
void	args_parsing(t_pipex *ppx, int argc, char **argv, char **envp);
char	**get_paths(char **envp);
char	***get_cmds(int num_cmds, char **argv);

// ft_ppxsplit_bonus.c
char	**ft_ppxsplit(char *s);

// child_bonus.c
void	child_process(t_pipex ppx, int fork_num, char **envp);

#endif