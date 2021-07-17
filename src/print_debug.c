/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 16:52:34 by ewatanab          #+#    #+#             */
/*   Updated: 2021/07/17 16:53:21 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	print_stack(t_ps *ps, t_dlist *stack)
{
	while (stack)
	{
		ft_putendl_fd(ft_itoa(ps->args[(t_ll)stack->content]), 1);
		stack = stack->next;
	}
}

void	print_args(t_ps *ps)
{
	size_t		i;

	i = 0;
	while (i < ps->arg_num)
		ft_putendl_fd(ft_itoa(ps->args[i++]), 1);
}

void	init_print_debug(t_ps *ps)
{
	ft_putendl_fd("args", 1);
	print_args(ps);
	ft_putendl_fd("stack_a", 1);
	print_stack(ps, ps->stack_a);
}
