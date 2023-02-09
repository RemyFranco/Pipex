/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfranco <rfranco@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:00:26 by rfranco           #+#    #+#             */
/*   Updated: 2023/01/10 15:08:03 by rfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief allocates memory for a copy of string s1 and does the copy.
/// @param s1 string that we want to duplicate
/// @return pointer to the new string or NULL if insufficient memory available.
char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*s;

	len = ft_strlen(s1);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	ft_strlcpy(s, s1, len + 1);
	return (s);
}
