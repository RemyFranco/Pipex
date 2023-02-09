/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfranco <rfranco@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:29:17 by rfranco           #+#    #+#             */
/*   Updated: 2023/01/09 14:12:52 by rfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief writes n zeroed bytes to the string s.
/// @param s void pointer to a memory location.
/// @param n number of zeroed bytes to write.
void	ft_bzero(void *s, size_t n)
{
	char	*str;

	str = (char *)s;
	while (n--)
		*str++ = '\0';
}
