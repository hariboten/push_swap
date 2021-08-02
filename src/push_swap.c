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

int		push_swap(t_ps *ps)
{
	int		ret_val;

	if (ft_lstsize(ps->stack_a) <= DFS_NLIM)
		ret_val = ps_dfs_sort(ps);
	else
		ret_val = ps_divaconq(ps);
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
