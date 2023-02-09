/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfranco <rfranco@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:53:52 by rfranco           #+#    #+#             */
/*   Updated: 2023/01/10 11:13:28 by rfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief locates the last occurence of c in the string s.
/// The function will also locate the terminating null character.
/// @param s pointer to a string
/// @param c value we are searching (converted to a char)
/// @return a pointer to the located character, or NULL if it does not appear.
char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*res;

	i = 0;
	res = NULL;
	while (s[i])
	{
		if (s[i] == (char)c)
			res = (char *)&s[i];
		i++;
	}
	if ((char)c == 0)
		res = (char *)&s[i];
	return (res);
}
