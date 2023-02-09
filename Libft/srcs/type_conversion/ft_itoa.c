/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfranco <rfranco@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:45:25 by rfranco           #+#    #+#             */
/*   Updated: 2023/01/12 13:51:52 by rfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(int n)
{
	size_t	count;

	count = 1;
	if (n < 0)
	{
		n = n * -1;
		count++;
	}
	while (n > 9)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

/// @brief allocates memory and returns a string representing the integer
/// received as an argument.
/// @param n the integer to convert
/// @return the string representing the integer. NULL if allocation fails.
char	*ft_itoa(int n)
{
	char	*str;
	size_t	i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = (char *)malloc(sizeof(char) * ft_intlen(n) + 1);
	if (!str)
		return (NULL);
	i = ft_intlen(n);
	str[i--] = '\0';
	if (n < 0)
	{
		n = n * -1;
		str[0] = '-';
	}
	while (n > 9)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	str[i] = n + '0';
	return (str);
}
