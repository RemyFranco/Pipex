/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfranco <rfranco@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:35:31 by rfranco           #+#    #+#             */
/*   Updated: 2023/02/13 16:14:42 by rfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	open_pipes(t_pipex *ppx, int argc)
{
	int	i;

	ppx->num_cmds = argc - 3;
	ppx->num_pipes = ppx->num_cmds - 1;
	ppx->num_pipe_fd = ppx->num_pipes * 2;
	ppx->pipe_fd = (int *)malloc(sizeof(int) * ppx->num_pipe_fd);
	if (!ppx->pipe_fd)
		exit_error("PIPE");
	i = 0;
	while (i < ppx->num_pipes)
	{
		if (pipe(ppx->pipe_fd + (2 * i)) == -1)
		{
			free(ppx->pipe_fd);
			exit_error("PIPE");
		}
		i++;
	}
}

void	close_pipes(t_pipex ppx)
{
	int	i;

	i = 0;
	while (i < ppx.num_pipe_fd)
	{
		close(ppx.pipe_fd[i]);
		i++;
	}
}

void	free_parent(t_pipex ppx)
{
	close_pipes(ppx);
	close(ppx.in_fd);
	close(ppx.out_fd);
	free(ppx.pipe_fd);
	free(ppx.pid);
	ft_freesplit(ppx.paths);
	free_cmds(ppx.cmds);
}

void	wait_all_pid(t_pipex ppx, int *status)
{
	int	i;

	i = 0;
	while (i < ppx.num_cmds)
	{
		waitpid(ppx.pid[i], status, 0);
		i++;
	}
	return ;
}

void	close_all(t_pipex ppx)
{
	close_pipes(ppx);
	close(ppx.in_fd);
	close(ppx.out_fd);
}
