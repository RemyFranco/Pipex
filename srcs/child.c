/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfranco <rfranco@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:26:39 by rfranco           #+#    #+#             */
/*   Updated: 2023/02/08 11:41:35 by rfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_command(char **paths, char *cmd)
{
	int		i;
	char	*command;

	i = 0;
	while (paths[i])
	{
		command = ft_strjoin(paths[i], cmd);
		if (access(command, F_OK) == 0)
			return (command);
		free(command);
		i++;
	}
	return (NULL);
}

void	child_1(t_pipex ppx, char **envp)
{
	char	*command;

	command = get_command(ppx.paths, ppx.cmds[0][0]);
	if (command == NULL)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putendl_fd(ppx.cmds[0][0], 2);
		exit (127);
	}
	close(ppx.pipe_fd[0]);
	dup2(ppx.in_fd, STDIN_FILENO);
	dup2(ppx.pipe_fd[1], STDOUT_FILENO);
	close(ppx.pipe_fd[1]);
	execve(command, ppx.cmds[0], envp);
	exit (127);
}

void	child_2(t_pipex ppx, char **envp)
{
	char	*command;

	command = get_command(ppx.paths, ppx.cmds[1][0]);
	if (command == NULL)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putendl_fd(ppx.cmds[1][0], 2);
		exit (127);
	}
	dup2(ppx.pipe_fd[0], STDIN_FILENO);
	dup2(ppx.out_fd, STDOUT_FILENO);
	close(ppx.pipe_fd[0]);
	close(ppx.pipe_fd[1]);
	execve(command, ppx.cmds[1], envp);
	exit (127);
}
