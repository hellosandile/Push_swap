/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_follow_instr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samkhize <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:30:22 by samkhize          #+#    #+#             */
/*   Updated: 2019/09/04 14:12:16 by samkhize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_follow(stack_a **a, stack_b **b, char *instr, int *s)
{
	if (ft_strequ(instr, "sa"))
		ft_swap_a(&*a, *s);
	else if (ft_strequ(instr, "sb"))
		ft_swap_b(&*b, *s);
	else if (ft_strequ(instr, "ss"))
		ft_swap_both(*a, *b);
	else if (ft_strequ(instr, "pa"))
		ft_push_a(&*a, &*b);
	else if (ft_strequ(instr, "pb"))
		ft_push_b(&*a, &*b);
	else if (ft_strequ(instr, "ra"))
		ft_shift_a(a, *s);
	else if (ft_strequ(instr, "rb"))
		ft_shift_b(b, 2);
	else if (ft_strequ(instr, "rr"))
		ft_shift_both(a, b, *s);
	else if (ft_strequ(instr, "rra"))
		ft_reverse_a(a, *s);
	else if (ft_strequ(instr, "rrb"))
		ft_reverse_b(b, 2);
	else if (ft_strequ(instr, "rrr"))
		ft_reverse_both(a, b, *s);
	return ;
}
// Will delete, but this is for printing what is in the stack to track progress
void		ft_print(struct node **head, int size)
{
	struct node *current;
	
	current = *head;
	if (size > 0)
	{
		while (size-- > 0)
		{
			ft_putstr(ft_itoa(current->data));
			ft_putchar('\t');
			current = current->next;
		}
	}
}
