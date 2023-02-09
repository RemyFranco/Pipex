/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfranco <rfranco@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:23:57 by rfranco           #+#    #+#             */
/*   Updated: 2023/01/12 12:50:54 by rfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isinset(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
		if (c == set[i++])
			return (1);
	return (0);
}

/// @brief allocates memory and returns a copy of 's1' with the characters
/// specified in the 'set'removed from the beginning and the end of the string.
/// @param s1 the string to be trimmed.
/// @param set the reference set of characters to trim.
/// @return the trimmed string. NULL if allocation fails.
char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*str;

	start = 0;
	while (isinset(s1[start], set))
		start++;
	if (start == ft_strlen(s1))
		return (ft_strdup(""));
	end = ft_strlen(s1) - 1;
	while (isinset(s1[end], set))
		end--;
	str = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (start <= end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
