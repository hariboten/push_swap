/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 18:55:54 by ewatanab          #+#    #+#             */
/*   Updated: 2021/07/18 12:51:59 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		restore(t_ps *ps, t_op op)
{
	if (op == OP_SA)
		return (op_sb(ps));
	if (op == OP_SB)
		return (op_sa(ps));
	if (op == OP_SS)
		return (op_ss(ps));
	if (op == OP_PA)
		return (op_pb(ps));
	if (op == OP_PB)
		return (op_pa(ps));
	if (op == OP_RA)
		return (op_rra(ps));
	if (op == OP_RB)
		return (op_rrb(ps));
	if (op == OP_RR)
		return (op_rrr(ps));
	if (op == OP_RRA)
		return (op_ra(ps));
	if (op == OP_RRB)
		return (op_rb(ps));
	if (op == OP_RRR)
		return (op_rr(ps));
	return (ps_error(E_INVOP));
}

int		operate(t_ps *ps, t_op op)
{
	if (op == OP_SA)
		return (op_sa(ps));
	if (op == OP_SB)
		return (op_sb(ps));
	if (op == OP_SS)
		return (op_ss(ps));
	if (op == OP_PA)
		return (op_pa(ps));
	if (op == OP_PB)
		return (op_pb(ps));
	if (op == OP_RA)
		return (op_ra(ps));
	if (op == OP_RB)
		return (op_rb(ps));
	if (op == OP_RR)
		return (op_rr(ps));
	if (op == OP_RRA)
		return (op_rra(ps));
	if (op == OP_RRB)
		return (op_rrb(ps));
	if (op == OP_RRR)
		return (op_rrr(ps));
	return (ps_error(E_INVOP));
}

bool	is_arranged(t_ps *ps)
{
	t_list	*it;

	if (ps->stack_b)
		return (false);
	it = ps->stack_a;
	while (it && it->next)
	{
		if ((t_ll)it->content > (t_ll)it->next->content)
			return (false);
		it = it->next;
	}
	return (true);
}

int		dfs_rec(t_ps *ps, t_dfs *dfs, t_op *op, int depth)
{
	int		min_cost;

	if (depth > dfs->max_depth)
		return (INT_MAX);
	if (is_arranged(ps))
		return (depth);
	ft_lstadd_front(&dfs->node_op, ft_lstnew(op));
	if (operate(ps, *op) < 0)
		return (INT_MAX);
	min_cost = search_next_node(ps, dfs, depth);
	ft_lstdelone(ft_lstpop_front(&dfs->node_op), NULL);
	restore(ps, *op);
	return (min_cost);
}

int		search_next_node(t_ps *ps, t_dfs *dfs, int depth)
{
	int		cost;
	int		min_cost;
	t_op	*next_op;

	next_op = ps->op_arr;
	while (*next_op != OP_NULL)
	{
		cost = dfs_rec(ps, dfs, next_op++, depth + 1);
		if (cost < 0)
			return (-1);
		if (cost >= min_cost)
			continue ;
		min_cost = cost;
		ft_lstclear(&dfs->optim_op, NULL);
		dfs->optim_op = ft_lstcopy(dfs->node_op);
	}
	return (min_cost);
}

int		ps_dfs_sort(t_ps *ps)
{
	int		min_cost;
	t_dfs	dfs;

	dfs.node_op = NULL;
	dfs.optim_op = NULL;
	dfs.max_depth = 1;
	min_cost = INT_MAX;
	while (min_cost == INT_MAX)
	{
		min_cost = search_next_node(ps, &dfs, 0);
		dfs.max_depth++;
	}
	ps->operations = dfs.optim_op;
	ft_lstclear(&dfs.node_op, NULL);
	return (min_cost);
}
