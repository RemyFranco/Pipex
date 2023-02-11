/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfranco <rfranco@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:25:50 by rfranco           #+#    #+#             */
/*   Updated: 2023/02/11 13:17:42 by rfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	ppx;
	int		status;

	status = 0;
	args_parsing(&ppx, argc, argv, envp);
	if (pipe(ppx.pipe_fd) == -1)
		exit_error("Error");
	ppx.pid1 = fork();
	if (ppx.pid1 == -1)
		exit_error("Error");
	else if (ppx.pid1 == 0)
		child_1(ppx, envp);
	ppx.pid2 = fork();
	if (ppx.pid2 == -1)
		exit_error("Error");
	else if (ppx.pid2 == 0)
		child_2(ppx, envp);
	close_and_free(ppx);
	waitpid(ppx.pid1, &status, 0);
	waitpid(ppx.pid2, &status, 0);
	if (status > 127)
		return (127);
	return (0);
}

/// @brief exits the program with exit(1). Only used to handle invalid number
/// of arguments.
void	exit_argc(void)
{
	ft_putendl_fd("Error: Invalid number of arguments", 2);
	ft_putendl_fd("Use format: \"infile\" \"cmd1\" \"cmd2\" \"oufile\"", 2);
	exit (1);
}

/// @brief displays msg on STDERR followed by errno.
/// Exits the program with exit(1).
/// @param msg the message that is displayed before errno.
void	exit_error(char *msg)
{
	perror(msg);
	exit (1);
}

void	free_cmds(char ***cmds)
{
	int	i;

	i = 0;
	while (cmds[i])
	{
		ft_freesplit(cmds[i]);
		i++;
	}
	free(cmds);
}

void	close_and_free(t_pipex ppx)
{
	close(ppx.pipe_fd[0]);
	close(ppx.pipe_fd[1]);
	close(ppx.in_fd);
	close(ppx.out_fd);
	ft_freesplit(ppx.paths);
	free_cmds(ppx.cmds);
}
