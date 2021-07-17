/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 16:54:40 by ewatanab          #+#    #+#             */
/*   Updated: 2021/07/17 17:41:16 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
 * invalid argument means
 * - non numeric argument
 *   - start with '0'
 *   - duplicate '-'
 *   - contain non numeric character
 * - bigger or smaller than INT range
 * - (duplicate value) <- Do NOT check here.
 *   - checked in coordinate_compression.c
 */
static bool		is_invalid_arg(const char *arg)
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

/*
 * - note. argv start with index 1.
 */
static int		input_arguments(t_ps *ps, int argc, char **argv)
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

static t_dlist	*llarr2dlist(t_ll *arr, size_t len)
{
	t_dlist *newlst;
	t_dlist *tmp;

	newlst = NULL;
	while (--len >= 0)
	{
		tmp = dlist_new((void *)arr[len]);
		if (!tmp)
		{
			dlist_destroy(&newlst, NULL);
			ps_error(E_ALLOC);
			return (NULL);
		}
		dlist_push_front(&newlst, tmp);
	}
	return (newlst);
}

/*
 * ps_init
 * - initilize ps object
 * - input_arguments
 * - coordinate_compression
 * - making stack_a from order arr
 */
int				ps_init(t_ps *ps, int argc, char **argv)
{
	t_ll	*order;
	int		ret_val;

	ps->arg_num = argc - 1;
	ps->stack_a = NULL;
	ps->stack_b = NULL;
	ps->operations = NULL;
	ps->args = malloc(ps->arg_num * sizeof(t_ll));
	if (!ps->args)
		return (ps_error(E_ALLOC));
	if (input_arguments(ps, argc, argv))
		return (-1);
	order = malloc(ps->arg_num * sizeof(t_ll));
	if (!order)
		return (ps_error(E_ALLOC));
	ret_val = coordinate_compression(order, ps->args, ps->arg_num);
	ps->stack_a = llarr2dlist(order, ps->arg_num);
	free(order);
	if (ret_val || !ps->stack_a)
		return (-1);
	return (0);
}
