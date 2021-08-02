#include <push_swap.h>

t_op	op_reverse(t_op op)
{
	if (op == OP_SA)
		return (OP_SA);
	if (op == OP_SB)
		return (OP_SB);
	if (op == OP_SS)
		return (OP_SS);
	if (op == OP_PA)
		return (OP_PB);
	if (op == OP_PB)
		return (OP_PA);
	if (op == OP_RA)
		return (OP_RRA);
	if (op == OP_RB)
		return (OP_RRB);
	if (op == OP_RR)
		return (OP_RRR);
	if (op == OP_RRA)
		return (OP_RA);
	if (op == OP_RRB)
		return (OP_RB);
	if (op == OP_RRR)
		return (OP_RR);
	return (ps_error(E_INVOP));
}

bool	is_reverse(t_list *l, t_list *r)
{
	if (!l || !r)
		return (false);
	if (*(t_op *)l->content == op_reverse(*(t_op *)r->content))
		return (true);
	return (false);
}

t_list	*ps_optimizer(t_list *operations)
{
	t_list *optimized;

	optimized = NULL;
	if (operations == NULL)
		return (NULL);
	while (operations)
	{
		if (is_reverse(operations, optimized))
		{
			ft_lstpop_front(&optimized);
			ft_lstpop_front(&operations);
		} else {
			ft_lstadd_front(&optimized, ft_lstpop_front(&operations));
		}
	}
	ft_lstreverse(&optimized);
	return (optimized);
}
