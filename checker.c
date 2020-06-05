/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samkhize <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:12:19 by samkhize          #+#    #+#             */
/*   Updated: 2019/08/16 08:57:43 by samkhize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_stacksorted(struct node *head)
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

int		main(int argc, char **argv)
{
	static stack_a	*stack;
	static stack_b	*temp;
	char			**res = NULL;
	char 			*str = NULL;
	static char		*instr;
	static int		i;
	int j;
	int				size = 2;
	char			*tempstr;
	
	if (argc < 2)
		return(0);
	if (argc >= 1 && ft_strequ(argv[1], "") == 0)
	{
		if ((stack = malloc(sizeof(stack_a))) == NULL)
			return (0);
		i = 1;
		if (stack != NULL)
		{
			if (argc == 2)
				str = argv[1];
			else if (argc > 2)
			{
				str = argv[1];
				j = 2;
				while (j < argc)
				{
					
					tempstr = ft_strjoin(str, " ");
					if (j > 2)
						free(str);
					str = ft_strjoin(tempstr, argv[j]);
					free(tempstr);
					j++;
				}
			}
			res = ft_strsplit(str, ' ');
			free(str);
			if (ft_handle(stack, res, &size))
			{
				i = 0;
				while(res[i])
				{
					free(res[i]);
					i++;
				}
				free(res);
				ft_free_linkedlist(stack);
				ft_free_linkedlist(temp);
				
				return (0);
			}
			if (ft_stacksorted(stack))
				{
					ft_free_linkedlist(stack);
					ft_free_linkedlist(temp);
					ft_putendl("OK");
					return 0;
				}
			while (get_next_line(0, &instr) == 1)
			{
				if (i == 1 && ft_strlen(instr) > 2)
				{
					
					if (ft_handle_instr(ft_instr(instr)))
					{
						ft_free_linkedlist(stack);
						ft_free_linkedlist(temp);
						ft_putendl_fd("Error", 2);
						return (0);
					}
				}
				else
				{
					if (ft_strequ(instr, ""))
						break;
					if (ft_handle_instr(instr))
					{
						ft_putendl_fd("Error", 2);
						ft_free_linkedlist(stack);
						ft_free_linkedlist(temp);
						return (0);
					}
				}
				ft_follow(&stack, &temp, instr, &size);
				free(instr);
				i++;
			}
			if (ft_stacksorted(stack) == 1)
				ft_putendl("OK");
			else
				ft_putendl("KO");
		}
	}
	i = 0;
	while(res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
	ft_free_linkedlist(stack);
	ft_free_linkedlist(temp);
	return (0);
}