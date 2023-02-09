/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfranco <rfranco@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:12:03 by rfranco           #+#    #+#             */
/*   Updated: 2023/01/18 14:05:43 by rfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief outputs the string 's' to the given file descriptor.
void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		ft_putchar_fd(*s++, fd);
}

int	ft_printstr_fd(char *s, int fd)
{
	int	count;

	count = 0;
	while (*s)
	{
		ft_putchar_fd(*s++, fd);
		count++;
	}
	return (count);
}
