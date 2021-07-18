/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:55:08 by ewatanab          #+#    #+#             */
/*   Updated: 2021/07/18 13:58:13 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>


int		ps_error(t_errno e)
{
	(void) e;
	ft_putstr_fd("Error\n", 2);
	return (-1);
}

int		push_swap(t_ps *ps)
{
	if (dlist_size(ps->stack_a) <= DFS_NLIM)
		return (ps_dfs_sort(ps));
	ft_putstr_fd("have not support more than DFS_NLIM arguments", 2);
	/*
	 * return (ps_qsort(ps));
	 */
	return (0);
}

void	ps_destroy(t_ps *ps)
{
	free(ps->args);
	free(ps->op_arr);
	dlist_destroy(&ps->stack_a, NULL);
	dlist_destroy(&ps->stack_b, NULL);
	dlist_destroy(&ps->operations, NULL);
	return ;
}
