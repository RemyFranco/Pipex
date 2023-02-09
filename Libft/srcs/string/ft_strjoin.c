/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfranco <rfranco@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:12:18 by rfranco           #+#    #+#             */
/*   Updated: 2023/01/23 10:15:26 by rfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief allocates memory and returns a new string, which is the result of
/// the concatenation of s1 and s2.
/// @param s1 the prefix string.
/// @param s2 the suffix string.
/// @return the new string. NULL if allocation fails.
char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}

/// @brief allocates memory and returns a new string, which is the result of
/// the concatenation of s1 and s2 + free s1.
/// @param s1 the prefix string.
/// @param s2 the suffix string.
/// @return the new string. NULL if allocation fails.
char	*ft_strjoin_free(char *s1, const char *s2)
{
	char	*str;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	free(s1);
	return (str);
}
