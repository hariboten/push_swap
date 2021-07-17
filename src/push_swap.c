/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:55:08 by ewatanab          #+#    #+#             */
/*   Updated: 2021/07/17 16:10:13 by ewatanab         ###   ########.fr       */
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

int		ps_error(t_errno e)
{
	(void) e;
	ft_putstr_fd("Error\n", 2);
	return (-1);
}

bool	is_invalid_arg(const char *arg)
{
	const char *p;

	p = arg;
	if (*p == '0')
		return (true);
	if (*p == '-')
		p++;
	while (*p)
	{
		if (*p < '0' || *p > '9')
			return (true);
		p++;
	}
	if (ft_atoi(arg) == INT_MAX && ft_strcmp(arg, "2147483647"))
		return (true);
	if (ft_atoi(arg) == INT_MIN && ft_strcmp(arg, "-2147483648"))
		return (true);
	return (false);
}

int		input_arguments(t_ps *ps, int argc, char **argv)
{
	int		i;

	if (argc < 2)
		return (ps_error(E_FEWARG));
	i = 0;
	while (i < argc - 1)
	{
		if (is_invalid_arg(argv[i + 1]))
			return (ps_error(E_INVARG));
		ps->args[i] = (t_ll)ft_atoi(argv[i + 1]);
		i++;
	}
	return (0);
}

int		ps_init(t_ps *ps, int argc, char **argv)
{
	t_ll	*order;

	ps->arg_num = argc - 1;
	ps->stack_a = NULL;
	ps->stack_b = NULL;
	ps->operations = NULL;
	ps->args = malloc(ps->arg_num * sizeof(t_ll));
	if (!ps->args || !order)
		return (ps_error(E_ALLOC));
	if (input_arguments(ps, argc, argv))
		return (-1);
	order = malloc(ps->arg_num * sizeof(t_ll));
	if (!order)
		return (ps_error(E_ALLOC));
	if (!coordinate_compression(order, ps->args, ps->arg_num))
	{
		free(order);
		return (-1);
	}
	ps->stack_a = dlist_arr2dlist(order, arg_num, sizeof(t_ll));
	free(order);
	if (!ps->stack_a)
		return (ps_error(E_ALLOC));
	return (0);
}

int		push_swap(t_ps *ps)
{
/*
	if (dlist_size(ps->stack_a) <= 6)
		return (ps_dfs_sort(ps));
	return (ps_qsort(ps));
*/
	return (0);
}

void	ps_destroy(t_ps *ps)
{
	free(ps->args);
	free(ps->order);
	dlist_destroy(&ps->stack_a, NULL);
	dlist_destroy(&ps->stack_b, NULL);
	dlist_destroy(&ps->operations, NULL);
	return ;
}
