/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:55:08 by ewatanab          #+#    #+#             */
/*   Updated: 2021/07/10 18:03:51 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		ps_init(t_ps *ps, int argc, char **argv);

int		push_swap(t_ps *ps)
{
	if (dlist_size(ps->stack_a) <= 6)
		return (ps_dfs_sort(ps));
	return (ps_qsort(ps));
}

void	ps_destroy(t_ps *ps);
