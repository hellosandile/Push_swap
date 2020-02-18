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
#include <stdio.h>

//Check the PDF for instructions. Also check how this was done in other repos

void		ft_push_a(stack_a **a, stack_b **b)
{
	stack_a *pa;
	stack_b **pb;
	//int	size;

	if (b)
	{
		pb = b;
		pa = malloc(sizeof(stack_a));
		pa->data = (*pb)->data;
		//pa->data = (*pb)->data;
		pa->next = *a;
		printf("%p\n", (void *) &pb);
		printf("%p\n", (void *) &a);

		*a = pa;
		ft_remove_first(&*b); // It removes the first value that is being moved
		//stack_b_size("minus");
		//stack_a_size(s, "add");
	}
	return ;
}

void		ft_push_b(stack_a **a, stack_b **b)
{
	stack_a **pa;
	stack_b *pb;

	if (a)
	{
		pa = a;
		pb = malloc(sizeof(stack_b));
		pb->data = (*pa)->data;
		pb->next = *b;
		*b = pb;
		ft_remove_first(&*a);
		//*a = (*a)->next; //need to delete the node being abandoned.
		//stack_a_size(s, "minus");
		//stack_b_size("add");
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
