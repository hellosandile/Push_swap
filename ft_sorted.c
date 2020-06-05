/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samkhize <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:39:03 by samkhize          #+#    #+#             */
/*   Updated: 2019/08/13 15:41:49 by samkhize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_sorted(stack_a *head)
{
	stack_a	*ptr;
	stack_a *c;
	int		size;
	int		val;

	size = 0;
	ptr = head;
	val = ptr->data;
	size = ft_listsize(head);
	if (size > 0)
	{
		while (ptr->next != NULL)
		{
			c = ptr;
			while (c->next != NULL)
			{
				if (c->data < val)
				{
					return (0);
				}
				c = c->next;
			}
			ptr = ptr->next;
			val = ptr->data;
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
			v = ptr->data;
			while (size-- > 1)
			{
				c = ptr->next;
				i = size;
				while (i-- > 1)
				{
					if (c->data > v)
						return (0);
					c = c->next;
				}
				ptr = ptr->next;
				v = ptr->data;
			}
		}
	}
	return (1);
}
