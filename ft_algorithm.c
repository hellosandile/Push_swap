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
	while (data[i] != NULL)
	{
		stack->next->data =  ft_atoi(data[i]);
		stack->next->next = (struct node *)malloc(sizeof(struct node));
	stack = stack->next;
		i++;
	}
	stack->next = NULL;
}

//using this to print what is in my current stack_a
void	ft_printlist(struct node *head)
{
	struct node *stack;

	stack = head;
	while (stack != NULL)
	{
		printf("%d", stack->data);
		stack = stack->next;
	}
}

int		head_g_last(struct node **head)
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


int		max(struct node **head)
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

int		min(struct node **head)
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

int		last(struct node **head)
{
	struct node *stack;
	stack = *head;
		while (stack->next != NULL)
			stack = stack->next;
	return (stack->data);
}

int		last_g_middle(struct node **head)
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

int		middle_g_last(struct node **head)
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

int		head_g_middle(struct node **head)
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


int		stacksorted(struct node *head)
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

int		desc_stacksorted(struct node *head)
{
	struct node *a, *b;
	a = head;
	while (a->next != NULL)
	{
		b = a->next;
		if (b->data > a->data)
			return 0;
		a = a->next;
	}
	return 1;
}

int		*create_range(int min, int max)
{
	int 	i;
	int 	r;
	int	max_f;
	int	*range = NULL;

	if (listsize(list) >= 100)
	{
		i = 0;
		if (listsize)
	}
}


/*
int main (int ac, char **av)
{
	char **data;
	stack_a *list;
	stack_b *listb;

	list = (stack_a *)malloc(sizeof(stack_a));
	listb = (stack_b *)malloc(sizeof(stack_b));
	listb = NULL;

	if (ac == 2)
	{
		data = ft_strsplit(av[1], ' ');
		initialize(&list, data);
		while (stack_sorted(&list) != 1)
		{
			if (last_g_middle(&list) == 0 && head_g_middle(&list) == 0
					&& head_g_last(&list) == 1)
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
		ft_printlist(listb);
		printf("\n");
		ft_printlist(list);
		
	}
	free(list);
	return (0);
}
*/
