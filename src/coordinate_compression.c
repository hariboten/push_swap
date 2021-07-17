/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_compression.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:37:24 by ewatanab          #+#    #+#             */
/*   Updated: 2021/07/17 16:09:59 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static bool	has_duplication(t_ll *arr, size_t len)
{
	int		i;
	t_ll	prev;

	prev = arr[0];
	i = 1;
	while (i < len)
	{
		if (prev == arr[i])
			return (true);
		prev = arr[i++];
	}
	return (false);
}

static void	ordering(t_ll *order, t_ll *sorted, size_t len)
{
	int		i;
	int		ok;
	int		ng;
	int		mid;

	i = 0;
	while (i < len)
	{
		ok = 0;
		ng = len;
		while (ng - ok > 1)
		{
			mid = ok + ng / 2;
			if (sorted[mid] >= order[i])
				ok = mid;
			else
				ng = mid;
		}
		order[i++] = sorted[ok];
	}
	return ;
}

int		coordinate_compression(t_ll *order, t_ll *arr, size_t len)
{
	t_ll	*sorted;

	sorted = malloc(len * sizeof(t_ll));
	if (!sorted)
		return (ps_error(E_ALLOC));
	ft_memcpy(sorted, arr, len * sizeof(t_ll));
	qsort_ll(sorted, len, less_ll);
	if (has_duplication(sorted, len))
	{
		free(sorted);
		return (ps_error(E_INVARG));
	}
	ordering(order, sorted, len);
	free(sorted);
	return (0);
}