/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samkhize <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:20:38 by samkhize          #+#    #+#             */
/*   Updated: 2019/08/29 13:54:12 by samkhize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac , char **av)
{
	char **data;
	stack_a *list;
	stack_b *listb;
	int size = 2;
//	stack_a *stack;

	list = (stack_a *)malloc(sizeof(stack_a));
	listb = (stack_b *)malloc(sizeof(stack_b));
	listb = NULL;

	if (ac == 2)
	{
		data = ft_strsplit(av[1], ' ');
		initialize(&list, data);

		if (list->data > last(&list) && list->next->data > last(&list))
		{
			ft_swap_a(&list, 2);
			ft_shift_a(&list, 2);
			ft_shift_a(&list, 2);
		}
		if (list->data > last(&list))
			ft_shift_a(&list, 2);


		ft_push_b(&list, &listb, &size);
		ft_push_b(&list, &listb, &size);
		while (stack_sorted(&list) != 1)
		{
			if (last_g_middle(&list) == 0 && head_g_middle(&list) == 0 && head_g_last(&list) == 1)
			{
				ft_reverse_a(&list, 3);
				ft_putendl("rra");
			}
			if (last_g_middle(&list) == 0 && head_g_middle(&list) == 1)
			{
				ft_shift_a(&list, 2);
				ft_putendl("ra");
			}
			if (last_g_middle(&list) == 1 && head_g_last(&list) == 1)
			{
				ft_shift_a(&list, 2);
				ft_putendl("ra");
			}
			if (head_g_middle(&list) == 1)
			{
				ft_swap_a(&list, 2);
				ft_putendl("sa");
			}
			if (head_g_middle(&list) == 0 && last_g_middle(&list) == 0)
			{
				ft_swap_a(&list, 2);
				ft_putendl("sa");
			}
		}
		if (head_g_last(&listb) == 0)
			ft_swap_b(&listb);
		if (listb->data > list->data && listb->data < list->next->data)
		{
			ft_push_a(&list, &listb, &size);
			ft_swap_a(&list, 2);
			ft_push_a(&list, &listb, &size);
			ft_swap_a(&list, 2);
		}
		if (listb->data > list->next->next->data)
		{
			ft_push_a(&list, &listb, &size);
			ft_shift_a(&list, 2);
		}
		while (listb != NULL)
		{
			if (listb->data < list->data)
				ft_push_a(&list, &listb, &size);
		}
	}
	ft_printlist(listb);
	printf("\n");
	ft_printlist(list);

	return 0;
}

