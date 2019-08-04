#include "push_swap.h"

void			ft_generate_b(stack_a *a, stack_b *b, int *size)
{
	int		s;

	while (ft_sorted_desc(b) == 0)
	{
		s = stack_b_size("");
		if (ft_is_less(&b))
		{
			ft_putendl("rb");
			ft_shift_b(&b, s);
		}
		if (ft_is_bigger(&b, s) && !ft_sorted_desc(b))
		{
			ft_putendl("pa");
			ft_push_a(&a, &b, size);
		}
		if (ft_is_bigger(&b, s))
		{
			ft_putendl("rrb");
			ft_reverse_b(&b, s);
		}
		else if (ft_first_state(b))
		{
			ft_putendl("sb");
			ft_swap_b(&b);
		}
	}
	while (ft_list_size(b) > 1)
	{
		s = stack_b_size("");
		ft_putendl("pa");
		ft_push_a(&a, &b, &s);
	}
}
