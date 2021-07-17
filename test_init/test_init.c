/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 16:07:59 by ewatanab          #+#    #+#             */
/*   Updated: 2021/07/11 16:09:37 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		main(int argc, char **argv)
{
	t_ps	ps;

	if (ps_init(&ps, argc, argv))
		return (-1);
	init_print_debug(&ps);
	ps_destroy(&ps);
	return (0);
}
