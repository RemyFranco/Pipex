/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfranco <rfranco@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:26:36 by rfranco           #+#    #+#             */
/*   Updated: 2023/01/10 12:29:45 by rfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief converts the initial portion of the string pointed to by str to
/// long int representation.
long	ft_atol(char *str)
{
	long int	nb;
	long int	sign;

	nb = 0;
	sign = 1;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		nb = (nb * 10) + (*str - '0');
		str++;
	}
	return (nb * sign);
}
