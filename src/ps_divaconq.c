/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_divaconq.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 15:15:19 by ewatanab          #+#    #+#             */
/*   Updated: 2021/08/02 15:43:28 by ewatanab         ###   ########.fr       */
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

t_list	*divaconq(t_list *stack_a, int begin, int end)
{
	t_list	*stack_b;
	t_lsit	*operations;
	int		pivot;
	int		i;
	int		top;

	pivot = (begin + end) / 2;
	i = end - begin;
	while (--i >= 0)
	{
		top = *(int *)stack_a->content;
		if (top < pivot)
			op_pb(stack_a, stack_b, operations);
		else
			op_ra(stack_a, stack_b, operations);
	}
	i = end - pivot;
	while (--i >= 0)
		op_rra(stack_a, stack_b, operations);
	ft_lstadd_back(&operations, divaconq(stack_a, pivot, end));
	i = pivot - begin;
	while (--i >= 0)
		op_pa(stack_a, stack_b, operations);
	ft_lstadd_back(&operations, divaconq(stack_a, begin, pivot));
	return (operations);
}
