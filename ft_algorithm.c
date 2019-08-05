#include "push_swap.h"

void		ft_generate_a(stack_a *a, stack_b *b, int *size)
{
	while (ft_sorted(a) == 0)
	{
		if (ft_is_less(&a))
		{
			ft_putendl("rra");
			ft_reverse_a(&a, *size);
		}
		if (ft_is_less(&a))
		{
			ft_putendl("pb");
			ft_push_b(&a, &b, size);
		}
		if (ft_is_bigger(&a, *size))
		{
			ft_putendl("ra");
			ft_shift_a(&a, *size);
		}
		else if (ft_first_state(a))
		{
			ft_putendl("sa");
			ft_swap_a(&a, *size);
		}
	}
	ft_generate_b(a, b, size);
}

int			ft_is_less(struct node **head)
{
	struct node *ptr;
	struct node *c;
	int			size;
	int			v;

	ptr = *head;
	size = ft_list_size(*head);
	if (size > 1)
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		v = ptr->v;
		c = *head;
		while (c->next != NULL)
		{
			if (c->v < v)
				return (0);
			c = c->next;
		}
	}
	return (1);
}

int			ft_first_state(struct node *head)
{
	struct node *ptr;

	ptr = head;
	if (ptr)
	{
		if (ptr->v > ptr->next->v)
			return (1);
	}
	return (0);
}

int			ft_is_bigger(struct node **head, int s)
{
	struct node *ptr;
	struct node *c;
	int			v;

	ptr = *head;
	if (ptr)
	{
		v = ptr->v;
		c = ptr->next;
		while (s-- > 1)
		{
			if (c->v > v)
				return (0);
			c = c->next;
		}
	}
	return (1);
}
