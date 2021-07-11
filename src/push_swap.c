/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:55:08 by ewatanab          #+#    #+#             */
/*   Updated: 2021/07/11 15:15:30 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

bool	cmp_less3(void *a, void *b, void *ref)
{
	t_ll	aa;
	t_ll	bb;
	t_ll	*ref_arr;

	ref_arr = ref;
	aa = (t_ll)a;
	bb = (t_ll)b;
	if (ref_arr[aa] < ref_arr[bb])
		return (true);
	return (false);
}

int		ps_error(t_errno e)
{
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
		if (is_invalid_arg(argv[i]))
			return (ps_error(E_INVARG));
		ps->args[i] = ft_atoi(argv[i]);

		i++;
	}
	return (0);
}

bool	has_duplication(t_ll *arr, t_dlist *index)
{
	t_ll	prev;

	prev = arr[(t_ll)index->content];
	index = index->next;
	while (index)
	{
		if (prev == arr[(t_ll)index->content])
			return (true);
		index = index->next;
	}
	return (false);
}

int		ps_init(t_ps *ps, int argc, char **argv)
{
	t_ll	i;

	ps->stack_a = NULL;
	ps->stack_b = NULL;
	ps->operations = NULL;
	ps->args = malloc((argc - 1) * sizeof(int));
	if (!ps->args)
		return (-1);
	if (input_arguments(ps, argc, argv))
	{
		free(ps->args);
		return (-1);
	}
	i = argc - 1;
	while (i >= 0)
		dlist_push_front(&ps->stack_a, dlist_new((void *)i--));
	if (dlist_size(ps->stack_a) != argc - 1)
	{
		free(ps->args);
		dlist_destroy(&ps->stack_a, NULL);
		return (-1);
	}
	dlist_qsort4(ps->stack_a, dlist_back(ps->stack_a), cmp_less3, ps->args);
	if (has_duplication(ps->args, ps->stack_a))
		return (-1);
	return (0);
}

int		push_swap(t_ps *ps)
{
	if (dlist_size(ps->stack_a) <= 6)
		return (ps_dfs_sort(ps));
	return (ps_qsort(ps));
}

void	ps_destroy(t_ps *ps)
{
	free(ps->args);
	dlist_destroy(&ps->stack_a, NULL);
	dlist_destroy(&ps->stack_b, NULL);
	dlist_destroy(&ps->operations, NULL);
	return ;
}
