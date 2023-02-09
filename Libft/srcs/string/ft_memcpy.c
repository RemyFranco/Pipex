/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfranco <rfranco@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:36:52 by rfranco           #+#    #+#             */
/*   Updated: 2023/01/09 14:13:00 by rfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief copies n bytes from src to dst. 
/// If dst and src overlap, behavior is undefined.
/// @param dst destination memory area.
/// @param src source memory area.
/// @param n number of bytes to copy.
/// @return its first argument (void *dst).
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*s;

	if (dst == NULL && src == NULL)
		return (NULL);
	d = (char *)dst;
	s = (char *)src;
	while (n--)
		*d++ = *s++;
	return (dst);
}
