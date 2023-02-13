/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfranco <rfranco@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:54:08 by rfranco           #+#    #+#             */
/*   Updated: 2023/02/13 16:17:00 by rfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	int		fork_num;
	int		status;
	t_pipex	ppx;

	fork_num = 0;
	status = 0;
	args_parsing(&ppx, argc, argv, envp);
	open_pipes(&ppx, argc);
	while (fork_num < ppx.num_cmds)
	{
		ppx.pid[fork_num] = fork();
		if (ppx.pid[fork_num] == -1)
		{
			free_parent(ppx);
			exit_error("Error");
		}
		else if (ppx.pid[fork_num] == 0)
			child_process(ppx, fork_num, envp);
		fork_num++;
	}
	close_all(ppx);
	wait_all_pid(ppx, &status);
	free_all(ppx);
	return (WEXITSTATUS(status));
}

/// @brief exits the program with exit(1). Only used to handle invalid number
/// of arguments.
void	exit_argc(void)
{
	ft_putendl_fd("Error: Invalid number of arguments", 2);
	ft_putendl_fd("Use format: <infile> <cmd1> <cmd2> <cmd...> <outfile>", 2);
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

void	free_all(t_pipex ppx)
{
	free(ppx.pipe_fd);
	free(ppx.pid);
	ft_freesplit(ppx.paths);
	free_cmds(ppx.cmds);
}
