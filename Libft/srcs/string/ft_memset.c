/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfranco <rfranco@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:07:24 by rfranco           #+#    #+#             */
/*   Updated: 2023/01/09 14:13:07 by rfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief writes len bytes of value c (converted to an unsigned char)
/// to the string b.
/// @param b void pointer to a memory location.
/// @param c value c.
/// @param len number of bytes that is written.
/// @return its first argument (void *b).
void	*ft_memset(void *b, int c, size_t len)
{
	char	*s;

	s = (char *)b;
	while (len--)
		*s++ = (unsigned char) c;
	return (b);
}
