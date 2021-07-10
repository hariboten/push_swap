/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 11:15:06 by ewatanab          #+#    #+#             */
/*   Updated: 2021/07/09 14:12:35 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dlist.h>
#include <stdio.h>
#include <stdlib.h>

bool	less_long(void *a, void *b)
{
	long	ai;
	long	bi;

	ai = (long)a;
	bi = (long)b;
	if (ai < bi)
		return (true);
	return (false);
}

int		main(int argc, char **argv)
{
	int		i;
	t_dlist	*lst;

	if (argc == 1)
	{
		printf("too few arg\n");
		return (-1);
	}
	lst = NULL;
	i = 1;
	while (i < argc)
		dlist_push_back(&lst, dlist_new((void *)(long)atoi(argv[i++])));
	dlist_qsort(lst, dlist_back(lst), less_long);
	while (lst)
	{
		printf("%ld\n", (long)lst->content);
		lst = lst->next;
	}
	dlist_destroy(&lst, NULL);
	return (0);
}
