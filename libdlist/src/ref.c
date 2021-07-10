/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ref.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 07:44:25 by ewatanab          #+#    #+#             */
/*   Updated: 2021/07/09 07:45:14 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dlist.h>

t_dlist			*dlist_front(t_dlist *lst)
{
	if (!lst)
		return (NULL);
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}

t_dlist			*dlist_back(t_dlist *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

size_t			dlist_size(t_dlist *lst)
{
	size_t	size;

	if (!lst)
		return (0);
	size = 1;
	lst = dlist_front(lst);
	while (lst->next)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

bool			dlist_empty(t_dlist *lst)
{
	if (!lst)
		return (true);
	return (false);
}
