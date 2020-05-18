#include "push_swap.h"

void		ft_reverse_a(stack_a **a, int s)
{
	stack_a	*ptr;

	ptr = *a;
	if (s > 1)
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ft_add_first(a, ptr->data);
		ft_remove_last(a);
		ptr->next = NULL;
	}
}

void		ft_reverse_b(stack_b **b, int s)
{
	stack_b *ptr;
	ptr = *b;
	
	if (s > 2)
	{
		while (ptr->next)
			ptr = ptr->next;
		ft_add_first(b, ptr->data);
		ft_remove_last(b);
		ptr->next = NULL;
	}
}

void		ft_reverse_both(stack_a **a, stack_b **b, int s)
{
	ft_reverse_a(a, s);
	ft_reverse_b(b, stack_b_size(""));
}
