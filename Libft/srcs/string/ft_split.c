/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfranco <rfranco@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:51:37 by rfranco           #+#    #+#             */
/*   Updated: 2023/01/25 14:03:26 by rfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief counts the number of words in 's' using 'c' as delimiter.
/// @return the number of words in the string.
static int	ft_wordcount(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s != c && *s)
				s++;
		}
		else
			s++;
	}
	return (count);
}

/// @brief allocates memory and returns a string using 'c' as delimiter.
/// @param s pointer to the start of the word.
/// @param c the delimiter character.
/// @return the new string.
static char	*ft_getword(const char *s, char c)
{
	size_t	i;
	char	*word;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

/// @brief allocates memory and returns an array of strings
/// obtained by splitting 's' using the 'c' as a delimiter.
/// The array ends with a NULL pointer.
/// @param s the string to be split. 
/// @param c the delimiter character.
/// @return the array of new strings resulting from the split.
/// NULL if the allocation fails.
char	**ft_split(const char *s, char c)
{
	char	**strs;
	size_t	i;

	strs = (char **)ft_calloc(ft_wordcount(s, c) + 1, sizeof(char *));
	if (!strs)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			strs[i] = ft_getword(s, c);
			if (!strs[i++])
			{
				ft_freesplit(strs);
				return (NULL);
			}
			while (*s != c && *s)
				s++;
		}
		else
			s++;
	}
	strs[i] = NULL;
	return (strs);
}

/// @brief free the memory allocated to the 
/// null terminated array of strings (char **).
/// @param strs the array of strings.
void	ft_freesplit(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		free (strs[i]);
		i++;
	}
	free (strs);
}
