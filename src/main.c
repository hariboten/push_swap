/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:43:44 by ewatanab          #+#    #+#             */
/*   Updated: 2021/07/17 15:18:35 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	main(int argc, char **argv)
{
	t_ps	ps;
	int		ret_val;

	ret_val = ps_init(&ps, argc, argv);
	if (ret_val == 0)
		ret_val = push_swap(&ps);
	ps_destroy(&ps);
	return (ret_val);
}
