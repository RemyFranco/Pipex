/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfranco <rfranco@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:51:27 by rfranco           #+#    #+#             */
/*   Updated: 2023/01/12 18:20:33 by rfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief adds the node 'new' at the beginning of the list.
/// @param lst the address of a pointer to the first link of a list.
/// @param new the address of a pointer to the node to be added to the list.
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*tmp;

	tmp = *lst;
	*lst = new;
	new->next = tmp;
}
