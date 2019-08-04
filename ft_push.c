#include "push_swap.h"


//Check the PDF for instructions. Also check how this was done in other repos

void		ft_push_a(stack_a **a, stack_b **b, int *s)
{
	stack_a *pa;
	stack_a **pb;
	int	size;

	if (stack_b_size("") > 0)
	{
		pb = b;
		pa = malloc(sizeof(stack_a));
		pa->v = (*pb)->v;
		pa->p = (*pb)->p;
		pa->next = *a;
		*a = pa;
		ft_remove_first(&*b); // It removes the first value that is being moved
		size = stack_b_size("minus");
		stack_a_size(s, "add");
	}
	return ;
}

void		ft_push_b(stack_a **a, stack_b **b, int *s)
{
	stack_a **pa;
	stack_b *pb;
	int		size;

	if (*s > 0)
	{
		pa = a;
		pb = malloc(sizeof(stack_b));
		pb->v = (*pa)->v;
		pb->p = (*pa)->p;
		pb->next = *b;
		*b = pb;
		ft_remove_first(&*a);
		stack_a_size(s, "minus");
		size = stack_b_size("add");
	}
	return ;
}

void		ft_push_both(stack_a **a, stack_b **b, int *s)
{
	ft_push_a(a, b, s);
	ft_push_b(a, b, s);
	return ;
}
