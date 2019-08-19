/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samkhize <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:20:31 by samkhize          #+#    #+#             */
/*   Updated: 2019/08/19 15:42:59 by samkhize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

//Here I am initialising the stack
void	initialize(struct node  **head, char **data)
{
	struct node *stack;
	//stack_b *stack2;

	int i = 0;
	stack = *head;
	stack->data = ft_atoi(data[i]);
	stack->next = NULL; //creating the first node in the stack
	while (stack->next != NULL)
		stack = stack->next; // looping through the stack
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



//using this to print what is in my current stack_a
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

/*
int		getnth(struct node **head, int tail)
{
	int count = 0;
	struct node *stack;
	stack = *head;
	while (stack != NULL)
	{
		if (count == tail)
			return (stack->data);
	}
	count++;
	stack = stack->next;
}
*/

int		get_tail(struct node **head)
{
	struct node *stack;
	int 		head_value;

	stack = *head;
	head_value = stack->data;
	while (stack->next != NULL)
	{
		stack = stack->next;
	}
	if (head_value > stack->data) //head > tail
		return (1);
	return (0);
}

int		get_middle(struct node **head)
{
	struct node *stack;
	int middle_value;

	stack = *head;
	middle_value = stack->next->data;
	while (stack->next != NULL)
		stack = stack->next;
	if (stack->data > middle_value) //tail > middle
		return 1;
	return 0;
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
		printf("\n\n");
		//printf("%d", get_middle(&list));
		if (get_middle(&list) == 1)
			ft_shift_a(&list, 2);
		ft_printlist(list);
	}
	free(list);
	return (0);
}

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
