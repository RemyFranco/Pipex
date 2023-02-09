/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfranco <rfranco@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:13:26 by rfranco           #+#    #+#             */
/*   Updated: 2023/01/18 14:08:29 by rfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief outputs the string 's' followed by a newline 
/// to the given file descriptor
void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

int	ft_printendl_fd(char *s, int fd)
{
	int	count;

	count = 0;
	count += ft_printstr_fd(s, fd);
	count += ft_printchar_fd('\n', fd);
	return (count);
}
