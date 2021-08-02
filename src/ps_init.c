/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 16:54:40 by ewatanab          #+#    #+#             */
/*   Updated: 2021/07/18 15:37:49 by ewatanab         ###   ########.fr       */
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
	if (*p == '0' && *(p + 1))
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
		ps->args[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (0);
}

static t_list	*arr2lst(int *arr, size_t len, void (*del)(void *))
{
	t_list *lst;
	t_list *new_node;

	if (!len)
		return (NULL);
	lst = arr2lst(arr + 1, len - 1, del);
	if (!lst && len - 1 != 0)
		return (NULL);
	new_node = ft_lstnew(arr);
	if (!new_node)
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	ft_lstadd_front(&lst, new_node);
	return (lst);
}

t_op		*init_op_arr()
{
	t_op	*op_arr;
	t_op	*it;
	t_op	op;

	op_arr = malloc((OP_NULL + 1) * sizeof(t_op));
	if (!op_arr)
		return (NULL);
	op = 0;
	it = op_arr;
	while (op <= OP_NULL)
		*it++ = op++;
	return (op_arr);
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
	ps->arg_num = argc - 1;
	ps->stack_a = NULL;
	ps->stack_b = NULL;
	ps->operations = NULL;
	ps->args = NULL;
	ps->op_arr =NULL;
	ps->order = NULL;
	if (argc < 2)
		return (ps_error(E_FEWARG));
	ps->args = malloc(ps->arg_num * sizeof(int));
	ps->op_arr = init_op_arr();
	if (!ps->args || !ps->op_arr)
		return (ps_error(E_ALLOC));
	if (input_arguments(ps, argc, argv))
		return (-1);
	ps->order = malloc(ps->arg_num * sizeof(int));
	if (!ps->order)
		return (ps_error(E_ALLOC));
	if (coordinate_compression(ps->order, ps->args, ps->arg_num))
		return (-1);
	ps->stack_a = arr2lst(ps->order, ps->arg_num, NULL);
	if (!ps->stack_a)
		return (-1);
	return (0);
}
