/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 14:24:28 by ewatanab          #+#    #+#             */
/*   Updated: 2021/07/17 15:10:44 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		less_ll(t_ll a, t_ll b)
{
	if (a < b)
		return (1);
	if (a > b)
		return (-1);
	return (0);
}

static void swap_ll(t_ll *a, t_ll *b)
{
	t_ll	tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
	return ;
}

static int	partition(t_ll *arr, size_t len, int (*cmp)(t_ll, t_ll))
{
	int		pivot;
	int		left;
	int		right;

	pivot = len - 1;
	left = 0;
	right = len - 1;
	while (true)
	{
		while (left < right && cmp(arr[left], arr[pivot]) <= 0)
			left++;
		while (left < right && cmp(arr[right], arr[pivot]) > 0)
			right--;
		if (left == right)
			break ;
		swap_ll(arr + left, arr + right);
	}
	if (left != pivot)
		swap_ll(arr + left, arr + pivot);
	return (left);
}

void	qsort_ll(t_ll *arr, size_t len, int (*cmp)(t_ll, t_ll))
{
	int		p;

	if (len < 2)
		return ;
	p = partition(arr, len, cmp);
	qsort_ll(arr, p, cmp);
	qsort_ll(arr + p + 1, len - p - 1, cmp);
	return ;
}
