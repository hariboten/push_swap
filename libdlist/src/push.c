/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 18:30:53 by ewatanab          #+#    #+#             */
/*   Updated: 2021/07/09 11:49:03 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dlist.h>

void			dlist_push_front(t_dlist **lst, t_dlist *newlst)
{
	t_dlist *lstfront;
	t_dlist	*newback;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = newlst;
		return ;
	}
	lstfront = dlist_front(*lst);
	newback = dlist_back(newlst);
	lstfront->next = newback;
	newback->prev = lstfront;
	*lst = dlist_front(newlst);
	return ;
}

void			dlist_push_back(t_dlist **lst, t_dlist *newlst)
{
	t_dlist	*newfront;
	t_dlist *lstback;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = newlst;
		return ;
	}
	lstback = dlist_back(*lst);
	newfront = dlist_front(newlst);
	lstback->next = newfront;
	newfront->prev = lstback;
	return ;
}

t_dlist			*dlist_insert(t_dlist **lst, t_dlist *newlst)
{
	t_dlist	*newlst_front;
	t_dlist	*newlst_back;

	if (!lst)
		return (NULL);
	if (!newlst)
		return (NULL);
	newlst_front = dlist_front(newlst);
	newlst_back = dlist_back(newlst);
	if (!*lst)
	{
		*lst = newlst_front;
		return (newlst_front);
	}
	(*lst)->prev->next = newlst_front;
	newlst_front->prev = (*lst)->prev;
	(*lst)->prev = newlst_back;
	newlst_back->next = *lst;
	return (newlst_front);
}
