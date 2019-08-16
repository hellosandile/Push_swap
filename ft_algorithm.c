/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samkhize <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:20:31 by samkhize          #+#    #+#             */
/*   Updated: 2019/08/16 08:34:17 by samkhize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

//Utility function to add an element size in the stach
void	push(struct node **head, int size)
{
	struct node* node = NULL;
	node = (struct node*)malloc(sizeof(struct node));

	if (!node)
	{
		printf("Heap Overflow\n");
		exit (0);
	}
	node->data = size;
	node->next = *head;
	*head = node;
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
