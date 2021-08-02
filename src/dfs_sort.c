/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 18:55:54 by ewatanab          #+#    #+#             */
/*   Updated: 2021/07/18 16:56:26 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

bool	is_arranged(t_ps *ps)
{
	t_list	*it;

	if (ps->stack_b)
		return (false);
	it = ps->stack_a;
	while (it && it->next)
	{
		if (*(int *)it->content > *(int *)it->next->content)
			return (false);
		it = it->next;
	}
	return (true);
}

int		dfs_rec(t_ps *ps, t_dfs *dfs, t_op *op, int depth)
{
	int		ret;

	if (depth > dfs->max_depth)
		return (0);
	if (operate(ps, *op) < 0)
		return (0);
	ft_lstadd_front(&dfs->node_op, ft_lstnew(op));
	if (is_arranged(ps))
	{
		ps->operations = ft_lstcopy(dfs->node_op, NULL);
		restore(ps, *op);
		ft_lstdelone(ft_lstpop_front(&dfs->node_op), NULL);
		return (1);
	}
	ret = search_next_node(ps, dfs, depth);
	ft_lstdelone(ft_lstpop_front(&dfs->node_op), NULL);
	restore(ps, *op);
	return (ret);
}

int		search_next_node(t_ps *ps, t_dfs *dfs, int depth)
{
	int		ret;
	t_op	*next_op;

	next_op = ps->op_arr;
	while (*next_op != OP_NULL)
	{
		ret = dfs_rec(ps, dfs, next_op++, depth + 1);
		if (ret < 0)
			return (-1);
		if (ret == 1)
			break ;
	}
	return (ret);
}

int		ps_dfs_sort(t_ps *ps)
{
	t_dfs	dfs;

	dfs.node_op = NULL;
	dfs.max_depth = 1;
	if (is_arranged(ps))
		return (0);
	while (search_next_node(ps, &dfs, 0) != 1)
		dfs.max_depth++;
	ft_lstclear(&dfs.node_op, NULL);
	return (0);
}
