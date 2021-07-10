/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 14:30:14 by ewatanab          #+#    #+#             */
/*   Updated: 2021/07/10 18:52:47 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include "../libdlist/include/dlist.h"

typedef struct s_ps t_ps;
typedef	struct s_op t_op;
typedef	long long t_ll;

struct	s_ps
{
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
	E_INVARG
}			t_errno;


/*
 * push_swap.c
 */
int		ps_init(t_ps *ps, int argc, char **argv);
int		push_swap(t_ps *ps);
void	ps_destroy(t_ps *ps);

/*
 * ps_sort.c
 */
int		ps_dfs_sort(t_ps *ps);
int		ps_qsort(t_ps *ps);

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

#endif
