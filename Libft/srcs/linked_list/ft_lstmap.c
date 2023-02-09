/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfranco <rfranco@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:29:27 by rfranco           #+#    #+#             */
/*   Updated: 2023/01/12 17:58:37 by rfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief iterates the list 'lst' and applies the function 'f' on the content
/// of each node. Creates a new list resulting of the successive application of
/// the successive application of the function 'f'. The 'del' function is used
/// to delete the content of a node if needed.
/// @param lst the beginning of the list to iterate on.
/// @param f the address of the function used to iterate on the list.
/// @param del the address of the function used to delete the cotent of a node.
/// @return the new list. NULL if allocation fails.
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*begin;
	t_list	*current;

	if (!lst)
		return (NULL);
	begin = ft_lstnew(f(lst->content));
	if (!begin)
		return (NULL);
	current = begin;
	while (lst->next)
	{
		lst = lst->next;
		current->next = ft_lstnew(f(lst->content));
		if (!current->next)
		{
			ft_lstclear(&begin, del);
			return (NULL);
		}
		current = current->next;
	}
	return (begin);
}
