/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfranco <rfranco@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:50:01 by rfranco           #+#    #+#             */
/*   Updated: 2023/01/09 15:55:32 by rfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief converts an upper-case letter to the corresponding lower-case letter.
/// @param c the tested character. 
/// Must be representable as an unsigned char or EOF.
/// @return if c is an upper-case letter, the corresponding lower-case letter.
/// Otherwise, the argument is returned unchanged. 
int	ft_toupper(int c)
{
	if (ft_isupper(c))
		return (c + 32);
	else
		return (c);
}
