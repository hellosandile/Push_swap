/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samkhize <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:33:09 by samkhize          #+#    #+#             */
/*   Updated: 2019/09/04 14:24:50 by samkhize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_push_a(stack_a **a, stack_b **b)
{
	stack_a *pa;
	stack_b **pb;

	if (b)
	{
		pb = b;
		pa = malloc(sizeof(stack_a));
		pa->data = (*pb)->data;
		pa->next = *a;
		*a = pa;
		ft_remove_first(&*b); 
	}
	return ;
}

void		ft_push_b(stack_a **a, stack_b **b)
{
// 	stack_a **pa;
	stack_b *pb;

	if (a)
	{
// 		pa = a;
		pb = malloc(sizeof(stack_b));
		pb->data = a->data;
		pb->next = *b;
		*b = pb;
		ft_remove_first(&*a);
		//free(pb);
	}
	return ;
}

void		ft_push_both(stack_a **a, stack_b **b, int *s)
{
	*s = 0;
	ft_push_a(a, b);
	ft_push_b(a, b);
	return ;
}
