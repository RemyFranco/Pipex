/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfranco <rfranco@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:00:51 by rfranco           #+#    #+#             */
/*   Updated: 2023/01/09 14:14:39 by rfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief copies len bytes from src to dst. Src and dst may overlap.
/// The copy is always done in a non-destructive manner (for dst).
/// @param dst destination memory area.
/// @param src source memory area.
/// @param len number of bytes to copy.
/// @return its first argument (void *dst).
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	if (dst > src)
		while (len--)
			d[len] = s[len];
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
