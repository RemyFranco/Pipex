/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfranco <rfranco@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:14:41 by rfranco           #+#    #+#             */
/*   Updated: 2023/01/09 15:46:02 by rfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief appends string src to the end of dst. 
/// It will append at most dstsize - strlen(dst) - 1 characters.
/// @param dst destination string
/// @param src source string
/// @param dstsize size of the destination buffer
/// @return the total length of the string the function tried to create:
/// initial length of dst + strlen(src).
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = ft_strlen(dst);
	j = 0;
	len = i + ft_strlen(src);
	if (dstsize <= i)
		return (dstsize + ft_strlen(src));
	while (i < dstsize - 1 && src[j])
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (len);
}
