/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 16:07:59 by ewatanab          #+#    #+#             */
/*   Updated: 2021/07/17 18:33:23 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		main(int argc, char **argv)
{
	t_ps	ps;
	int		ret_val;

	ret_val = ps_init(&ps, argc, argv);
	if (ret_val == 0)
		init_print_debug(&ps);
	ps_destroy(&ps);
	return (ret_val);
}
