/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_func_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 11:58:09 by ewatanab          #+#    #+#             */
/*   Updated: 2021/07/18 12:10:19 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	st_swap(t_list *stack)
{
	void	*tmp;

	tmp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = tmp;
	return ;
}

int		op_sa(t_ps *ps)
{
	if (!ps->stack_a || !ps->stack_a->next)
		return (-1);
	st_swap(ps->stack_a);
	return (0);
}

int		op_sb(t_ps *ps)
{
	if (!ps->stack_b || !ps->stack_b->next)
		return (-1);
	st_swap(ps->stack_b);
	return (0);
}

int		op_ss(t_ps *ps)
{
	if (!ps->stack_a || !ps->stack_a->next)
		return (-1);
	if (!ps->stack_b || !ps->stack_b->next)
		return (-1);
	st_swap(ps->stack_b);
	st_swap(ps->stack_b);
	return (0);
}
