/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfranco <rfranco@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:10:11 by rfranco           #+#    #+#             */
/*   Updated: 2023/01/12 13:35:49 by rfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief allocates memory and create a substring from string s.
/// @param s the string from which the substring is extracted.
/// @param start the start index of the substring in the string s. 
/// @param len the maximum length of the substring.
/// @return the substring, or NULL if allocation fails.
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	substr_len;
	size_t	i;
	char	*substr;

	if (start >= ft_strlen(s) || len == 0)
	{
		substr = (char *)ft_calloc(1, sizeof(char));
		if (!substr)
			return (NULL);
		return (substr);
	}
	substr_len = ft_strlen(s) - start;
	if (substr_len > len)
		substr_len = len;
	substr = (char *)malloc(sizeof(char) * (substr_len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (len-- && s[start])
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}
