#include "push_swap.h"

int			ft_sorted(stack_a *head)
{
	stack_a	*ptr;
	stack_a *c;
	int		size;
	int		val;

	size = 0;
	ptr = head;
	val = ptr->v;
	size = ft_list_size(head);
	if (size > 0)
	{
		while (ptr->next != NULL)
		{
			c = ptr;
			while (c->next != NULL)
			{
				if (c->v < val)
				{
					return (0);
				}
				c = c->next;
			}
			ptr = ptr->next;
			val = ptr->v;
		}
	}
	else
		return (0);
	return (1);
}

int			ft_sorted_desc(stack_b *head)
{
	stack_b *ptr;
	stack_b *c;
	int		v;
	int		size;
	int		i;

	ptr = head;
	size = stack_b_size("");
	if (head != NULL)
	{
		if (size > 0)
		{
			v = ptr->v;
			while (size-- > 1)
			{
				c = ptr->next;
				i = size;
				while (i-- > 1)
				{
					if (c->v > v)
						return (0);
					c = c->next;
				}
				ptr = ptr->next;
				v = ptr->v;
			}
		}
	}
	return (1);
}
