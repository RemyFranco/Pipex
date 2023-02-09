/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfranco <rfranco@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 22:04:02 by rfranco           #+#    #+#             */
/*   Updated: 2023/02/07 16:59:38 by rfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	args_parsing(t_pipex *ppx, int argc, char **argv, char **envp)
{
	if (argc != 5)
		exit_argc();
	ppx->num_cmds = argc - 3;
	ppx->in_fd = open(argv[1], O_RDONLY);
	if (ppx->in_fd == -1)
	{
		printf("%d\n", errno);
		exit_error(argv[1]);
	}
	ppx->out_fd = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (ppx->out_fd == -1)
		exit_error(argv[argc - 1]);
	ppx->paths = get_paths(envp);
	ppx->cmds = get_cmds(ppx->num_cmds, argv);
}

/// @brief extracts all the paths from envp and adds a terminating '/'.
/// @param envp environment variables.
/// @return an array of strings containing all the executables paths.
char	**get_paths(char **envp)
{
	int		i;
	char	*tmp;
	char	*path;
	char	**paths;

	while (ft_strncmp("PATH", *envp, 4) != 0)
		envp++;
	path = *envp + 5;
	paths = ft_split(path, ':');
	i = 0;
	while (paths[i])
	{
		tmp = paths[i];
		paths[i] = ft_strjoin(paths[i], "/");
		free(tmp);
		i++;
	}
	return (paths);
}

/// @brief extracts all the commands (argv[2] -> argv[argc - 2]).
/// split the arguments (e.g. "wc -l" to "wc" "-l") and allocates
/// memory for the result.
/// @param num_cmds number of commands (argc - 3)
/// @return an array of array of strings. NULL if allocation fails.
char	***get_cmds(int num_cmds, char **argv)
{
	int		i;
	int		j;
	char	***cmds;

	i = 0;
	j = 2;
	cmds = (char ***)malloc(sizeof(char **) * (num_cmds + 1));
	if (!cmds)
		exit_error("Error");
	while (i < num_cmds)
	{
		cmds[i] = ft_ppxsplit(argv[j]);
		if (!cmds[i])
		{
			free_cmds(cmds);
			exit_error("Error");
		}
		i++;
		j++;
	}
	cmds[i] = NULL;
	return (cmds);
}
