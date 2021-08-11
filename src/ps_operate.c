#include <push_swap.h>

t_list	*op_lstnew(t_ps *ps, t_op op)
{
	t_op	*p_op_arr;

	p_op_arr = ps->op_arr;
	while (*p_op_arr != OP_NULL)
	{
		if (*p_op_arr == op)
			return (ft_lstnew(p_op_arr));
		p_op_arr++;
	}
	return (NULL);
}

int	operate3(t_ps *ps, t_op op, t_list **operations)
{
	int		ret;

	ret = operate(ps, op);
	if (ret == 0)
		ft_lstadd_front(operations, op_lstnew(ps, op));
	return (ret);
}

char	*op_get_name(t_op op)
{
	if (op == OP_SA)
		return ("sa");
	if (op == OP_SB)
		return ("sb");
	if (op == OP_SS)
		return ("ss");
	if (op == OP_PA)
		return ("pa");
	if (op == OP_PB)
		return ("pb");
	if (op == OP_RA)
		return ("ra");
	if (op == OP_RB)
		return ("rb");
	if (op == OP_RR)
		return ("rr");
	if (op == OP_RRA)
		return ("rra");
	if (op == OP_RRB)
		return ("rrb");
	if (op == OP_RRR)
		return ("rrr");
	return ("invalid operation");
}

int	restore(t_ps *ps, t_op op)
{
	if (op == OP_SA)
		return (op_sa(ps));
	if (op == OP_SB)
		return (op_sb(ps));
	if (op == OP_SS)
		return (op_ss(ps));
	if (op == OP_PA)
		return (op_pb(ps));
	if (op == OP_PB)
		return (op_pa(ps));
	if (op == OP_RA)
		return (op_rra(ps));
	if (op == OP_RB)
		return (op_rrb(ps));
	if (op == OP_RR)
		return (op_rrr(ps));
	if (op == OP_RRA)
		return (op_ra(ps));
	if (op == OP_RRB)
		return (op_rb(ps));
	if (op == OP_RRR)
		return (op_rr(ps));
	return (ps_error(E_INVOP));
}

int	operate(t_ps *ps, t_op op)
{
	if (op == OP_SA)
		return (op_sa(ps));
	if (op == OP_SB)
		return (op_sb(ps));
	if (op == OP_SS)
		return (op_ss(ps));
	if (op == OP_PA)
		return (op_pa(ps));
	if (op == OP_PB)
		return (op_pb(ps));
	if (op == OP_RA)
		return (op_ra(ps));
	if (op == OP_RB)
		return (op_rb(ps));
	if (op == OP_RR)
		return (op_rr(ps));
	if (op == OP_RRA)
		return (op_rra(ps));
	if (op == OP_RRB)
		return (op_rrb(ps));
	if (op == OP_RRR)
		return (op_rrr(ps));
	return (ps_error(E_INVOP));
}
