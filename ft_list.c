/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samkhize <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:30:41 by samkhize          #+#    #+#             */
/*   Updated: 2019/09/04 14:42:55 by samkhize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_list_size(struct node *head)
{
	struct node	*ptr;
	int			len;

	len = 0;
	ptr = head;
	if (ptr != NULL)
	{
		while (ptr->next != NULL)
		{
			len++;
			ptr = ptr->next;
		}
	}
	return (len);
}

int		listsize(struct node *head)
{
	struct node *begin_list;
	int i;

	i = 0;
	begin_list = head;
	while (begin_list != NULL)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (i);
}

int			stack_b_size(char *oper)
{
	static int num = 1;

	if (ft_strequ(oper, "add"))
		num++;
	else if (ft_strequ(oper, "minus"))
		num--;
	return (num);
}

void		stack_a_size(int *size, char *oper)
{
	if (ft_strequ(oper, "add"))
		*size = *size + 1;
	else if (ft_strequ(oper, "minus"))
		*size = *size - 1;
}

void		ft_add_first(struct node **head, int value)
{
	struct node *item;

	item = malloc(sizeof(struct node));
	item->data = value;
	item->ptr = 0;
	item->next = *head;
	*head = item;
	return ;
}

void		ft_remove_first(struct node **head)
{
	struct node	*ptr;

	ptr = (*head)->next;
	*head = ptr;
	// *head = (*head)->next;
	return ;
}

void		ft_remove_last(struct node **head)
{
	struct node *ptr;

	//s = 0;
	ptr = *head;
	if (!(ptr->next))
		return ; //if you want it to remove stuff length 1 put it here;
	while (ptr->next->next) //go until 2nd last
		ptr = ptr->next;
	free(ptr->next);
	ptr->next = NULL;
	return ;
}

void		ft_populate(stack_a *head, char **stack, int *size)
{
	stack_a	*ptr;
	int		i;

	i = 0;
	ptr = head;
	if (ptr != NULL)
	{
		ptr->data = ft_atoi(stack[i]); //first value of the stack
		ptr->ptr = i;
		ptr->next = NULL;
		i++;
	}
	//here it is looping through the list till it reaches NULL
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = malloc(sizeof(stack_a)); //allocating space for the next value
	while (stack[i])
	{
		ptr->next->data = ft_atoi(stack[i]);
		ptr->next->ptr = i;
		ptr->next->next = malloc(sizeof(stack_a));
		ptr = ptr->next;
		i++;
	}
	ptr->next = NULL;
	*size = i; // Here you now know that the *size is the size of the list which
	//is the end result of i
}
