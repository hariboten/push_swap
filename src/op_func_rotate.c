/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_func_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 12:20:59 by ewatanab          #+#    #+#             */
/*   Updated: 2021/07/18 12:28:48 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	st_rotate(t_list **stack)
{
	t_list *to_back;

	if (!(*stack)->next)
		return ;
	to_back = ft_lstpop_front(stack);
	ft_lstadd_back(stack, to_back);
	return ;
}

int		op_ra(t_ps *ps)
{
	if (!ps->stack_a)
		return (-1);
	st_rotate(&ps->stack_a);
	return (0);
}

int		op_rb(t_ps *ps)
{
	if (!ps->stack_b)
		return (-1);
	st_rotate(&ps->stack_b);
	return (0);
}

int		op_rr(t_ps *ps)
{
	if (!ps->stack_a)
		return (-1);
	if (!ps->stack_b)
		return (-1);
	st_rotate(&ps->stack_a);
	st_rotate(&ps->stack_b);
	return (0);
}
