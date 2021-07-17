/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 14:30:14 by ewatanab          #+#    #+#             */
/*   Updated: 2021/07/17 17:05:36 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include "../libdlist/include/dlist.h"
# include "../libft/libft.h"

typedef struct s_ps t_ps;
typedef	struct s_op t_op;
typedef	long long t_ll;

struct	s_ps
{
	size_t	arg_num;
	t_ll	*args;
	t_dlist	*stack_a;
	t_dlist	*stack_b;
	t_dlist	*operations;
};

struct	s_op
{
	char	*operation;
	void	(*op_func)(t_op *);
};

typedef enum e_errno
{
	E_FEWARG = 1,
	E_INVARG,
	E_ALLOC
}			t_errno;


/*
 * push_swap.c
 */
int		push_swap(t_ps *ps);
void	ps_destroy(t_ps *ps);
int		ps_error(t_errno e);

/*
 * ps_sort.c
 */
int		ps_dfs_sort(t_ps *ps);
int		ps_qsort(t_ps *ps);

/*
 * qsort_ll.c
 */
int		less_ll(t_ll a, t_ll b);
void	qsort_ll(t_ll *arr, size_t len, int (*cmp)(t_ll, t_ll));

/*
 * op_func_swap.c
 */
void	op_sa(t_ps *ps);
void	op_sb(t_ps *ps);
void	op_ss(t_ps *ps);

/*
 * op_func_push.c
 */
void	op_pa(t_ps *ps);
void	op_pb(t_ps *ps);

/*
 * op_func_rotate.c
 */
void	op_ra(t_ps *ps);
void	op_rb(t_ps *ps);
void	op_rr(t_ps *ps);

/*
 * op_func_rev_rotate.c
 */
void	op_rra(t_ps *ps);
void	op_rrb(t_ps *ps);
void	op_rrr(t_ps *ps);

/*
 * ps_init.c
 */
int		ps_init(t_ps *ps, int argc, char **argv);

/*
 * coordinate_compression.c
 */
int		coordinate_compression(t_ll *order, t_ll *arr, size_t len);

/*
 * print_debug.c
 */
void	init_print_debug(t_ps *ps);

#endif
