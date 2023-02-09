/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfranco <rfranco@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:25:05 by rfranco           #+#    #+#             */
/*   Updated: 2023/01/12 17:28:53 by rfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief iterates the list 'lst' and applies the function 'f' on the content
/// of each node.
/// @param lst the beginning of the list.
/// @param f the address of the function used to iterate on the list.
void	ft_lstiter(t_list *lst, void *(*f)(void *))
{
	while (lst)
	{
		lst->content = f(lst->content);
		lst = lst->next;
	}
}
