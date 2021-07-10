/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 18:10:09 by ewatanab          #+#    #+#             */
/*   Updated: 2021/07/09 08:33:10 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dlist.h>


t_dlist	*dlist_new(void *content)
{
	t_dlist	*lst;

	lst = malloc(sizeof(t_dlist));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	lst->prev = NULL;
	return (lst);
}

void	dlist_destroy(t_dlist **lst, void (*del)(void *))
{
	t_dlist	*tmp;

	*lst = dlist_front(*lst);
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		if (del)
			del(tmp->content);
		free(tmp);
	}
	return ;
}

t_dlist	*dlist_copy(t_dlist *lst)
{
	t_dlist	*newlst;

	newlst = NULL;
	lst = dlist_back(lst);
	while (lst)
	{
		dlist_push_front(&newlst, dlist_new(lst->content));
		lst = lst->prev;
	}
	return (newlst);
}
