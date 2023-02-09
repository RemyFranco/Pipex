/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfranco <rfranco@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:15:49 by rfranco           #+#    #+#             */
/*   Updated: 2023/01/18 14:26:21 by rfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief outputs the integer 'n'to the given file descriptor.
/// @param n the integer to output.
/// @param fd the file descriptor on which to write.
void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			n = -n;
			ft_putchar_fd('-', fd);
		}
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
		}
		ft_putchar_fd((n % 10) + '0', fd);
	}
}

int	ft_printnbr_fd(int n, int fd)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count += ft_printstr_fd("-2147483648", fd);
		return (count);
	}
	else
	{
		if (n < 0)
		{
			n = -n;
			count += ft_printchar_fd('-', fd);
		}
		if (n > 9)
		{
			count += ft_printnbr_fd(n / 10, fd);
		}
		count += ft_printchar_fd((n % 10) + '0', fd);
	}
	return (count);
}
