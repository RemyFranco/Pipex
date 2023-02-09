/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfranco <rfranco@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:54:31 by rfranco           #+#    #+#             */
/*   Updated: 2023/01/12 14:00:18 by rfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief allocates memory and creates a new string by applying the 
/// function 'f' to each character of string 's'.
/// @param s the string on which to iterate.
/// @param f the function to apply to each character.
/// @return the string created from the successive applications of 'f'.
/// NULL if allocation fails.
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}		
	str[i] = '\0';
	return (str);
}
