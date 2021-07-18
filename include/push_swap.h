/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 14:30:14 by ewatanab          #+#    #+#             */
/*   Updated: 2021/07/18 14:24:01 by ewatanab         ###   ########.fr       */
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

# define DFS_NLIM 6

typedef struct s_ps t_ps;
typedef	struct s_dfs t_dfs;
typedef	long long t_ll;

typedef enum e_errno
{
	E_FEWARG = 1,
	E_INVARG,
	E_ALLOC,
	E_INVOP
}			t_errno;

typedef enum e_op
{
	OP_SA = 0,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_NULL
}			t_op;

struct	s_ps
{
	size_t	arg_num;
	int		*args;
	t_op	*op_arr;
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*operations;
};

struct	s_dfs
{
	t_list	*node_op;
	t_list	*optim_op;
	int		max_depth;
};

/*
 * push_swap.c
 */
int		push_swap(t_ps *ps);
void	ps_destroy(t_ps *ps);
int		ps_error(t_errno e);

/*
 * ps_sort.c
 */
int		search_next_node(t_ps *ps, t_dfs *dfs, int depth);
int		ps_dfs_sort(t_ps *ps);
int		ps_qsort(t_ps *ps);

/*
 * qsorti.c
 */
int		lessi(int a, int b);
void	qsorti(int *arr, size_t len, int (*cmp)(int, int));

/*
 * ps_init.c
 */
int		ps_init(t_ps *ps, int argc, char **argv);

/*
 * coordinate_compression.c
 */
int		coordinate_compression(int *order, int *arr, size_t len);

/*
 * print_debug.c
 */
void	init_print_debug(t_ps *ps);

/*
 * list_util.c
 */
t_list	*ft_lstcopy(t_list *src, void (*del)(void *));
t_list	*ft_lstpop_front(t_list **lst);
t_list	*ft_lstpop_back(t_list **lst);

/*
 * op_func_swap.c
 */
int		op_sa(t_ps *ps);
int		op_sb(t_ps *ps);
int		op_ss(t_ps *ps);

/*
 * op_func_push.c
 */
int		op_pa(t_ps *ps);
int		op_pb(t_ps *ps);

/*
 * op_func_rotate.c
 */
int		op_ra(t_ps *ps);
int		op_rb(t_ps *ps);
int		op_rr(t_ps *ps);

/*
 * op_func_rev_rotate.c
 */
int		op_rra(t_ps *ps);
int		op_rrb(t_ps *ps);
int		op_rrr(t_ps *ps);
#endif
