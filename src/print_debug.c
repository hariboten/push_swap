/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 16:52:34 by ewatanab          #+#    #+#             */
/*   Updated: 2021/07/18 16:54:06 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	print_stack(t_ps *ps, t_list *stack)
{
	char 	*text;

	(void)ps;
	while (stack)
	{
		text = ft_itoa(*(int *)stack->content);
		ft_putendl_fd(text, 1);
		free(text);
		stack = stack->next;
	}
}

void	print_args(t_ps *ps)
{
	size_t		i;
	char 		*text;

	i = 0;
	while (i < ps->arg_num)
	{
		text = ft_itoa(ps->args[i++]);
		ft_putendl_fd(text, 1);
		free(text);
	}
}

void	print_oplst(t_list *oplst)
{
	if (!oplst)
		return;
	print_oplst(oplst->next);
	ft_putendl_fd(op_get_name(*(t_op *)oplst->content), 1);
	return ;
}

void	init_print_debug(t_ps *ps)
{
	ft_putendl_fd("args", 1);
	print_args(ps);
	ft_putendl_fd("stack_a", 1);
	print_stack(ps, ps->stack_a);
}
