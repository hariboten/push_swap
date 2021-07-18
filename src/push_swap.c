/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:55:08 by ewatanab          #+#    #+#             */
/*   Updated: 2021/07/18 16:54:32 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>


int		ps_error(t_errno e)
{
	(void) e;
	ft_putstr_fd("Error\n", 2);
	return (-1);
}

char	*op_get_name(t_op op)
{
	if (op == OP_SA)
		return ("sa");
	if (op == OP_SB)
		return ("sb");
	if (op == OP_SS)
		return ("ss");
	if (op == OP_PA)
		return ("pa");
	if (op == OP_PB)
		return ("pb");
	if (op == OP_RA)
		return ("ra");
	if (op == OP_RB)
		return ("rb");
	if (op == OP_RR)
		return ("rr");
	if (op == OP_RRA)
		return ("rra");
	if (op == OP_RRB)
		return ("rrb");
	if (op == OP_RRR)
		return ("rrr");
	return ("invalid operation");
}

int		push_swap(t_ps *ps)
{
	int		ret_val;

	if (ft_lstsize(ps->stack_a) <= DFS_NLIM)
		ret_val = ps_dfs_sort(ps);
	else
	{
		ft_putstr_fd("have not support more than DFS_NLIM arguments", 2);
		ret_val = -1;
	}
	/*
	 * return (ps_qsort(ps));
	 */
	print_oplst(ps->operations);
	return (ret_val);
}

void	ps_destroy(t_ps *ps)
{
	free(ps->args);
	free(ps->op_arr);
	free(ps->order);
	ft_lstclear(&ps->stack_a, NULL);
	ft_lstclear(&ps->stack_b, NULL);
	ft_lstclear(&ps->operations, NULL);
	return ;
}
