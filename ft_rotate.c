/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samkhize <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:38:40 by samkhize          #+#    #+#             */
/*   Updated: 2019/08/20 12:48:44 by samkhize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_shift_a(stack_a **a, int s)
{
	stack_a *ptr;
	
	ptr = *a;

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
		while (ptr->next != NULL)
		{
			ft_swap_b(&ptr, s);
			ptr = ptr->next;
		}
	}
}

void		ft_shift_both(stack_a **a, stack_b **b, int s)
{
	ft_shift_a(a, s);
	ft_shift_b(b, stack_b_size(""));
}