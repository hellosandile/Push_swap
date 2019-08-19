/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samkhize <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:20:31 by samkhize          #+#    #+#             */
/*   Updated: 2019/08/19 11:58:49 by samkhize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

//Utility function to add an element size in the stack
void	initialize(struct node  **head, char **data)
{
	struct node *stack;
	//stack_b *stack2;

	int i = 0;
	stack = *head;
	stack->data = ft_atoi(data[i]);
	stack->next = NULL;
	while (stack->next != NULL)
		stack = stack->next;
	stack->next =  malloc(sizeof(struct node));
	i = 1;
	while (data[i] != '\0')
	{
		stack->next->data =  ft_atoi(data[i]);
		stack->next->next = (struct node *)malloc(sizeof(struct node));
	stack = stack->next;
		i++;
	}
	stack->next = NULL;
}

void	ft_printlist(stack_a *head)
{
	stack_a *stack;

	stack = head;
	while (stack != NULL)
	{
		printf("%d", stack->data);
		stack = stack->next;
	}
}

int main (int ac, char **av)
{
	char **data;
	stack_a *list;

	list = (stack_a *)malloc(sizeof(stack_a));
	
	if (ac == 2)
	{
		data = ft_strsplit(av[1], ' ');
		initialize(&list, data);
		ft_printlist(list);
	}
	free(list);
	return (0);
}




//!!!create a main that will take in the ints on the stack


/* sorting algorithm for 3 numbers
 *
 * if tail is smallest & head is the biggest
 * 		rotate
 *
 * if head > tail & tail  > middle
 * 		rotate
 *
 * if head > middle
 * 		swap
 *
 * if head is small & tail < middle
 * 		rotate
 *
 */
