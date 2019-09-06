/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samkhize <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 09:23:38 by samkhize          #+#    #+#             */
/*   Updated: 2019/09/06 13:23:33 by samkhize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/* first be able to sort 1 stack with a bubble sort.
 * Then be able to find the median value
 * Then be able to sort in decending order
 *
 * */


int	main(int ac, char **av)
{
	char **data;
	stack_a *list;

	list = (stack_a *)malloc(sizeof(stack_a));

	if (ac == 2)
	{
		data = ft_strsplit(av[1], ' ');
		initialize(&list, data);

		while (stacksorted(list) != 1)
		{
			if (list->data > list->next->data)
			{
				ft_shift_a(&list, 2);
				//ft_putendl("sa");
			}
			else
			{
				ft_swap_a(&list, 2);
				//ft_putendl("ra");
			}
		}
	}
	ft_printlist(list);

	return 0;
}
