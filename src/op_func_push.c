/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_func_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 12:10:52 by ewatanab          #+#    #+#             */
/*   Updated: 2021/07/18 12:19:55 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>


int		op_pa(t_ps *ps)
{
	t_list	*to_push;

	if (!ps->stack_b)
		return (-1);
	to_push = ft_lstpop_front(&ps->stack_b);
	/*
	 * to_push = ps->stack_b;
	 * ps->stack_b = ps->stack_b->next;
	 * to_push->next = NULL;
	 */
	ft_lstadd_front(&ps->stack_a, to_push);
	return (0);
}

int		op_pb(t_ps *ps)
{
	t_list	*to_push;

	if (!ps->stack_a)
		return (-1);
	to_push = ft_lstpop_front(&ps->stack_a);
	ft_lstadd_front(&ps->stack_b, to_push);
	return (0);
}
