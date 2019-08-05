#include "push_swap.h"

void		ft_shift_a(stack_a **a, int s)
{
	stack_a *ptr;
	//stack_a	*c;
	//int		size;

	ptr = *a;
	//c = *a;
	//size = s;
	if (s > 1)
	{
		while (ptr->next != NULL)
		{
			ft_swap_a(&ptr, s);
			ptr = ptr->next;
		}
	}
}

void		ft_shift_b(stack_b **b, int s)
{
	stack_b *ptr;

	ptr = *b;
	if (s > 1)
	{
		while (s-- > 1)
		{
			ft_swap_b(&ptr);
			ptr = ptr->next;
		}
	}
}

void		ft_shift_both(stack_a **a, stack_b **b, int s)
{
	ft_shift_a(a, s);
	ft_shift_b(b, stack_b_size(""));
}
