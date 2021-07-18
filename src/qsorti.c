/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort_ll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 14:24:28 by ewatanab          #+#    #+#             */
/*   Updated: 2021/07/18 14:18:42 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		lessi(int a, int b)
{
	if (a < b)
		return (-1);
	if (a > b)
		return (1);
	return (0);
}

static void swapi(int *a, int *b)
{
	int	tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
	return ;
}

static int	partition(int *arr, size_t len, int (*cmp)(int, int))
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
		swapi(arr + left, arr + right);
	}
	if (left != pivot)
		swapi(arr + left, arr + pivot);
	return (left);
}

void	qsorti(int *arr, size_t len, int (*cmp)(int, int))
{
	int		p;

	if (len < 2)
		return ;
	p = partition(arr, len, cmp);
	qsorti(arr, p, cmp);
	qsorti(arr + p + 1, len - p - 1, cmp);
	return ;
}
