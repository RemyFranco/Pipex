/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfranco <rfranco@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:53:02 by rfranco           #+#    #+#             */
/*   Updated: 2023/01/10 12:10:29 by rfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief locates the first occurence of the needle in the haystack.
/// @param haystack nul-terminated string.
/// @param needle nul-terminated string.
/// @param len number of characters that are searched.
/// @return a pointer to the first character of the first occurence of needle.
/// If needle is empty, haystack is returned.
/// If needle is not found, NULL is returned.
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = ft_strlen(needle);
	if (i == 0)
		return ((char *)haystack);
	while (len && *haystack)
	{
		if (ft_strncmp(haystack, needle, i) == 0 && i <= len)
			return ((char *)haystack);
		len--;
		haystack++;
	}
	return (NULL);
}
