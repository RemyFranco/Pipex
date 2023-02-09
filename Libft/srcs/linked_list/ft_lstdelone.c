/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfranco <rfranco@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:09:46 by rfranco           #+#    #+#             */
/*   Updated: 2023/01/12 17:13:06 by rfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief takes as a parameter a node and frees the memory of the
/// node's content using the function 'del' given as a parameter and
/// free the node. The memory of 'next' must not be freed.
/// @param lst the node to free.
/// @param del the address of the function used to delete the content.
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}
