/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:55:08 by ewatanab          #+#    #+#             */
/*   Updated: 2021/07/17 17:44:46 by ewatanab         ###   ########.fr       */
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
	(void) ps;
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
	dlist_destroy(&ps->stack_a, NULL);
	dlist_destroy(&ps->stack_b, NULL);
	dlist_destroy(&ps->operations, NULL);
	return ;
}
