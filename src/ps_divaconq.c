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

/*
 * stack_a
 *  - int *content
 *
 * operations
 *  - t_op *content
 */

int		st_top(t_list *stack)
{
	return (*(int *)stack->content);
}

t_list	*op_lstnew(t_ps *ps, t_op op)
{
	t_op *p_op_arr;

	p_op_arr = ps->op_arr;
	while (*p_op_arr != OP_NULL)
	{
		if (*p_op_arr == op)
			return (ft_lstnew(p_op_arr));
		p_op_arr++;
	}
	return (NULL);
}

int		operate3(t_ps *ps, t_op op, t_list **operations)
{
	int		ret;

	ret = operate(ps, op);
	if (ret == 0)
		ft_lstadd_back(operations, op_lstnew(ps, op));
	return (ret);
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
