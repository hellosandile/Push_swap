#include "push_swap.h"

// Go throught the PDF to see how these instructions are described and coded below
void		ft_swap_a(stack_a **a, int s)
{
	stack_a **ptr;
	int		temp;
	int		size;

	ptr = a;
	size = s;
	if (size > 1 && (*ptr)->next != NULL)
	{
		temp = (*ptr)->v;
		(*ptr)->v = (*ptr)->next->v;
		(*ptr)->next->v = temp;
	}
}

void		ft_swap_b(stack_b **b)
{
	stack_b **ptr;
	int		temp;

	if (stack_b_size("") > 1)
	{
		ptr = b;
		temp = (*ptr)->v;
		(*ptr)->v = (*ptr)->next->v;
		(*ptr)->next->v = temp;
	}
}

void		ft_swap_both(stack_a *a, stack_b *b)
{
	ft_swap_a(&a, 2);
	ft_swap_b(&b);
}
