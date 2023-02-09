/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfranco <rfranco@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:06:51 by rfranco           #+#    #+#             */
/*   Updated: 2023/01/18 14:04:18 by rfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief outputs the characters 'c' to the given file descriptor.
/// @param c the character to output.
/// @param fd the file descriptor on which to write.
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_printchar_fd(char c, int fd)
{
	ft_putchar_fd(c, fd);
	return (1);
}
