#include "push_swap.h"

void		ft_reverse_a(stack_a **a, int s)
{
	stack_a	*ptr;

	ptr = *a;
	if (s > 1)
	{
		while (s-- > 1)
			ptr = ptr->next;
		ft_add_first(&*a, ptr->v);
		ft_remove_last(&ptr, s);
	}
}

void		ft_reverse_b(stack_b **b, int s)
{
	stack_b *ptr;
	
	ptr = *b;
	if (s > 1)
	{
		while (s-- > 1)
			ptr = ptr->next;
		ft_add_first(&*b, ptr->v);
		ft_remove_last(&ptr, s);
	}
}

void		ft_reverse_both(stack_a **a, stack_b **b, int s)
{
	ft_reverse_a(a, s);
	ft_reverse_b(b, stack_b_size(""));
}
