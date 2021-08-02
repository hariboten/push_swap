/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_divaconq.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 15:15:19 by ewatanab          #+#    #+#             */
/*   Updated: 2021/08/02 16:19:36 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		st_top(t_list *stack)
{
	return (*(int *)stack->content);
}

t_list	*divaconq(t_ps *ps, int begin, int end)
{
	t_list	*operations;
	int		pivot;
	int		i;

	if (end - begin < 2)
		return (NULL);
	pivot = (begin + end) / 2;
	i = end - begin;
	while (--i >= 0)
	{
		if (st_top(ps->stack_a) < pivot)
			operate3(ps, OP_PB, &operations);
		else
			operate3(ps, OP_RA, &operations);
	}
	i = end - pivot;
	while (--i >= 0)
		operate3(ps, OP_RRA, &operations);
	ft_lstadd_back(&operations, divaconq(ps, pivot, end));
	i = pivot - begin;
	while (--i >= 0)
		operate3(ps, OP_PA, &operations);
	ft_lstadd_back(&operations, divaconq(ps, begin, pivot));
	return (operations);
}
