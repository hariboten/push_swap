/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 13:06:39 by ewatanab          #+#    #+#             */
/*   Updated: 2021/07/18 13:27:41 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>



t_list	*ft_lstcopy(t_list *src, void (*del)(void *))
{
	t_list	*copy;
	t_list	*new_node;

	if (!src)
		return (NULL);
	copy = ft_lstcopy(src->next, del);
	if (!copy && src->next)
		return (NULL);
	new_node = ft_lstnew(src->content);
	if (!new_node)
	{
		ft_lstclear(&copy, del);
		return (NULL);
	}
	ft_lstadd_front(&copy, new_node);
	return (copy);
}

t_list	*ft_lstpop_front(t_list **lst)
{
	t_list	*front;

	if (!*lst)
		return (NULL);
	front = *lst;
	*lst = (*lst)->next;
	front->next = NULL;
	return (front);
}

t_list	*ft_lstpop_back(t_list **lst)
{
	t_list	*it;
	t_list	*back;

	if (!*lst)
		return (NULL);
	it = *lst;
	if (!it->next)
	{
		back = *lst;
		*lst = NULL;
		return (back);
	}
	while (it->next->next)
		it = it->next;
	back = it->next;
	it->next = NULL;
	return (back);
}

void	ft_lstjoin_front(t_list **lst, t_list *newlst)
{
	if (!*lst)
	{
		*lst = newlst;
		return ;
	}
	if (!newlst)
		return ;
	ft_lstlast(newlst)->next = *lst;
	*lst = newlst;
	return ;
}
