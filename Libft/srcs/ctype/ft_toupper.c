/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfranco <rfranco@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:50:01 by rfranco           #+#    #+#             */
/*   Updated: 2023/01/09 15:54:20 by rfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief converts a lower-case letter to the corresponding upper-case letter.
/// @param c the tested character. 
/// Must be representable as an unsigned char or EOF.
/// @return if c is a lower-case letter, the corresponding upper-case letter.
/// Otherwise, the argument is returned unchanged. 
int	ft_toupper(int c)
{
	if (ft_islower(c))
		return (c - 32);
	else
		return (c);
}
