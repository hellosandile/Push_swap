/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samkhize <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:20:31 by samkhize          #+#    #+#             */
/*   Updated: 2019/09/06 13:14:34 by samkhize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_initialize(struct node  **head, char **data)
{
	struct node *stack;

	int i = 0;
	stack = *head;
	stack->data = ft_atoi(data[i]);
	stack->next = NULL;
	//while (stack->next != NULL)
	//	stack = stack->next;
	stack->next =  malloc(sizeof(struct node));
	i = 1;
	while (data[i] != NULL)
	{
		stack->next->data =  ft_atoi(data[i]);
		{
			if (data[i + 1] != NULL)
				stack->next->next = (struct node *)malloc(sizeof(struct node));
		}
		stack = stack->next;
		i++;
	}
	stack->next = NULL;
}

int		ft_head_g_last(struct node **head)
{
	struct node *stack;
	int 		head_value;

	stack = *head;
	head_value = stack->data;
	while (stack->next != NULL)
	{
		stack = stack->next;
	}
	if (head_value > stack->data)
		return (1);
	return (0);
}

int		ft_max(struct node **head)
{
	struct node *stack;
	stack = *head;
	int	max;
	max = stack->data;
	while (stack != NULL)
	{
		if (max < stack->data)
			max = stack->data;
		stack = stack->next;
	}
	return (max);

}

int		ft_min(struct node **head)
{
	struct node *stack;
	stack = *head;
	int	min;
	min = stack->data;
	while (stack != NULL)
	{
		if (stack->data < min)
			min = stack->data;
		stack = stack->next;
	}
	return (min);
}

int		ft_mid(int size)
{
	if ((size % 2) == 0)
		return (size / 2);
	else
		return ((size / 2) + 1);
}

void		ft_get_biggest(struct node **head)
{
	struct node  *stack;
	int	back = 0;
	int	front = 0;
	int	value;
	stack = *head;
	if (ft_listsize(stack) == 0)
		return ;
	value = stack->data;
	while (stack->next != NULL)
	{
		if (value < stack->next->data)
			value = stack->next->data;
		stack = stack->next;
	}
	stack = *head;
	while (stack->next && stack->data != value)
	{
		front++;
		stack = stack->next;
	}
	stack = stack->next;
	while(stack)
	{
		back++;
		stack = stack->next;
	}
	if (front > back || back == 0)
	{
		while (back-- > -1)
		{
			if (!ft_sorted_desc((stack_b *)*head))
				return;
			ft_reverse_b((stack_b **)head, ft_listsize((stack_b *)*head));
			ft_putendl("rrb");
		}
	}
	else
	{
		while (front-- > 0)
		{
			if (!ft_sorted_desc((stack_b *)*head))
				return ;
			ft_shift_b((stack_b **)head, ft_listsize((stack_b *)*head));
			ft_putendl("rb");
		}
	}
}

int		ft_last(struct node **head)
{
	struct node *stack;
	stack = *head;
		while (stack->next != NULL)
			stack = stack->next;
	return (stack->data);
}

int		ft_last_g_middle(struct node **head)
{
	struct node *stack;
	int middle_value;


	stack = *head;
	middle_value = stack->next->data;
	while (stack->next != NULL)
		stack = stack->next;
	if (stack->data > middle_value)
		return 1;
	return 0;
}

int		ft_middle_g_last(struct node **head)
{
	struct node *stack;
	int middle_value;

	stack = *head;
	middle_value = stack->next->data;
	while (stack->next != NULL)
		stack = stack->next;
	if (stack->data < middle_value)
		return 1;
	return 0;
}

int		ft_head_g_middle(struct node **head)
{
	struct node *stack;
	int		head_value;
	int		middle_value;

	stack = *head;
	head_value = stack->data;
	middle_value = stack->next->data;
	if (head_value > middle_value)
		return 1;
	return 0;
}


int		ft_stacksorted(struct node *head)
{
	struct node *a, *b;
	a = head;
	while (a->next != NULL)
	{
		b = a->next;
		if (b->data < a->data)
			return 0;
		a = a->next;
	}
	return 1;
}

int		*ft_create_range(int min, int max, int size)
{
	int 	i;
	int 	r;
	int	max_f;
	int	*range = NULL;

	if (size >= 50 && size <= 100)
	{
		i = 0;
		range = (int *)malloc(sizeof(int) * 5);
		r = (max - min) / 5;
		r += (max - min % 5 == 0) ? 0 : 1;
		max_f = r + (min - 1);
		range[i] = max_f;
		if (max_f < 0)
			max_f = 19;
		while (++i < 4)
			range[i] = range[i - 1] + max_f;
		range[i] = max;
		}
	return(range);
}

int		*ft_create_big_range(int min, int max, int size)
{
	int 	i;
	int 	r;
	int	max_f;
	int	*range = NULL;

	if (size > 100)
	{
		i = 0;
		range = (int *)malloc(sizeof(int) * 11);
		r = (max - min) / 11;
		r += (max - min % 5 == 0) ? 0 : 1;
		max_f = r + (min - 1);
		range[i] = max_f;
		if (max_f < 0)
			max_f = 45;
		while (++i < 10)
			range[i] = range[i - 1] + max_f;
		range[i] = max;
	}
	return(range);
}

int			ft_big_value(stack_a *head)
{
	stack_a *stack;
	stack_a *current;

	stack = head;
	current = head;
	while (current->next != NULL)
	{
		if (current->next->data > stack->data)
			return (0);
		current = current->next;
	}
	return (1);
}

int			ft_first_sec_value(stack_a *head, int size)
{
	stack_a *stack;

	stack = head;
	if (size > 1)
	{
		if (stack->data > stack->next->data)
			return (1);
	}
	return (0);
}

int			ft_less_value(stack_a *head, int size)
{
	stack_a *stack;
	stack_a *current;

	stack = head;
	if (size > 1)
	{
		while (stack->next != NULL)
			stack = stack->next;
		current = head;
		while (current->next != NULL)
		{
			if (current->next->data < stack->data)
				return (0);
			current = current->next;
		}
	}
	return (1);
}

void		ft_sort_more_than_100(stack_a **a, stack_b **b)
{
	int	maxi;
	int	mini;
	int	*range;
	int	i;
	int	size;
	stack_a *list;

	i = 0;
	list = *a;
	mini = ft_min(&list);
	maxi = ft_max(&list);

	range = ft_create_big_range(mini, maxi, ft_listsize(list));
	size = ft_listsize(list);
	while ( size > 1)
	{
		list = *a;
		i = 0;
		while (list && ++i)
		{
			if (list->data >= mini && list->data < *range)
			{
				if (ft_mid(size) >= i)
				{
					while (i-- > 1)
					{
						ft_shift_a(a, ft_listsize(*a));
						ft_putendl("ra");
					}
					i = 0;
				}
				else
				{
					while (i-- > 0)
					{
						ft_reverse_a(a, ft_listsize(*a));
						ft_putendl("rra");
					}
					i = 0;
				}
				ft_get_biggest(b);
				ft_push_b(a, b);
				ft_putendl("pb");
				list = *a;
				size--;
			}
			else
				list = list->next;
		}
		mini = *range;
		range++;
	}
	while (ft_listsize(*b) > 0)
	{
		ft_get_biggest(b);
		ft_push_a(a, b);
		ft_putendl("pa");
		if (ft_big_value(*a))
		{
			if (!ft_stacksorted(*a))
			{
				ft_putendl("ra");
				ft_shift_a(a, ft_listsize(*a));
			}
		}

		if (ft_less_value(*a, ft_listsize(*a)))
		{
			if (!ft_stacksorted(*a))
			{
				ft_putendl("rra");
				ft_reverse_a(a, ft_listsize(*a));
			}
		}

		if (ft_first_sec_value(*a, ft_listsize(*a)))
		{
			if (!ft_stacksorted(*a))
			{
				ft_swap_a(a, ft_listsize(*a));
				ft_putendl("sa");
			}
		}
	}
}

void		ft_sort_100(stack_a **a, stack_b **b)
{
	int	maxi;
	int	mini;
	int	*range;
	int	i;
	int	size;
	stack_a *list;

	i = 0;
	list = *a;
	mini = ft_min(&list);
	maxi = ft_max(&list);

	range = ft_create_range(mini, maxi, ft_listsize(list));
	size = ft_listsize(list);
	while ( size > 1)
	{
		list = *a;
		i = 0;

		while (list && ++i)
		{
			if (list->data >= mini && list->data < *range)
			{
				if (ft_mid(size) >= i)
				{
					while (i-- > 1)
					{
						ft_shift_a(a, ft_listsize(*a));
						ft_putendl("ra");
					}
					i = 0;
				}
				else
				{
					while (i-- > 0)
					{
						ft_reverse_a(a, ft_listsize(*a));
						ft_putendl("rra");
					}
					i = 0;
				}
				ft_get_biggest(b);
				ft_push_b(a, b);
				ft_putendl("pb");
				list = *a;
				size--;
			}
			else
				list = list->next;
		}
		mini = *range;
		range++;
	}
	while (ft_listsize(*b) > 0)
	{
		ft_get_biggest(b);
		ft_push_a(a, b);
		ft_putendl("pa");
		if (ft_big_value(*a))
		{
			if (!ft_stacksorted(*a))
			{
				ft_putendl("ra");
				ft_shift_a(a, ft_listsize(*a));
			}
		}

		if (ft_less_value(*a, ft_listsize(*a)))
		{
			if (!ft_stacksorted(*a))
			{
				ft_putendl("rra");
				ft_reverse_a(a, ft_listsize(*a));
			}
		}

		if (ft_first_sec_value(*a, ft_listsize(*a)))
		{
			if (!ft_stacksorted(*a))
			{
				ft_swap_a(a, ft_listsize(*a));
				ft_putendl("sa");
			}
		}
	}
}

void	ft_sort_three(stack_a **a)
{
	stack_a *list;
	list = *a;

	while (ft_stacksorted(list) != 1)
	{
		if (ft_last_g_middle(&list) == 0 && ft_head_g_middle(&list) == 0 && ft_head_g_last(&list) == 1)
		{
			ft_reverse_a(&list, 3);
			ft_putendl("rra");
		}
		if (ft_last_g_middle(&list) == 0 && ft_head_g_middle(&list) == 1)
		{
			ft_shift_a(&list, 2);
			ft_putendl("ra");
		}
		if (ft_last_g_middle(&list) == 1 && ft_head_g_last(&list) == 1)
		{
			ft_shift_a(&list, 2);
			ft_putendl("ra");
		}
		if (ft_head_g_middle(&list) == 1)
		{
			ft_swap_a(&list, 2);
			ft_putendl("sa");	
		}
		if (ft_head_g_middle(&list) == 0 && ft_last_g_middle(&list) == 0)
		{
			ft_swap_a(&list, 2);
			ft_putendl("sa");
		}
	}
	*a = list;
}

void	ft_sort_five(stack_a **a, stack_b **b)
{
	stack_a *list;
	stack_b *listb;
	list = *a;
	listb = *b;
	
	while (ft_listsize(list) > 3 && ft_stacksorted(list) == 0)
		{
			if (ft_last(&list) == ft_min(&list))
			{
				ft_reverse_a(&list, ft_listsize(list));
				ft_putendl("rra");
			}
			 if (list->data != ft_min(&list))
			{
				ft_shift_a(&list, 2);
				ft_putendl("ra");
			}
			if (list->data == ft_min(&list))
			{
				ft_push_b(&list, &listb);
				//free(listb);
				ft_putendl("pb");
			}
			//free(listb);
		}
		while (ft_stacksorted(list) != 1)
			ft_sort_three(&list);
		while (ft_listsize(listb) > 0)
		{
			ft_push_a(&list, &listb);
			ft_putendl("pa");
		}
		if (ft_listsize(listb) == 0)
			listb = NULL;
		*a = list;
		return; 
}