/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samkhize <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:12:19 by samkhize          #+#    #+#             */
/*   Updated: 2019/08/12 14:19:45 by samkhize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int c, char **argv)
{
	static stack_a	*stack;
	static stack_b	*temp;
	char			**res;
	static char		*instr;
	static int		i;
	int				size;
//Creating memory for the 2 stacks
	if ((stack = malloc(sizeof(stack_a))) == NULL)
		return (0);
	if ((temp = malloc(sizeof(stack_b))) == NULL)
		return (0);
	//Checking that there is an argument
	if (c > 1 && ft_strequ(argv[1], "") == 0)
	{
		i = 1;
		if (stack != NULL)
		{
			res = ft_strsplit(argv[1], ' ');
			if (ft_handle(stack, res, &size))
			{
				free(stack);
				free(temp);
				return (0);
			}
			// Here we are reading instructions from the stdin using fd 0
			while (get_next_line(0, &instr) == 1)
			{
				if (i == 1 && ft_strlen(instr) > 2) // must be 2 bcuz 
					//instrunctions from PDF has a min of 2 in the instruction
				{
					if (ft_handle_instr(ft_instr(instr)))
					{
						ft_putendl_fd("Error", 2);
						return (0);
					}
				}
				else
				{
					if (ft_handle_instr(instr))
					{
						ft_putendl_fd("Error", 2);
						return (0);
					}
				}
				ft_putendl(instr); // not neccessary since this only shows 
				//					the instrunctions
				ft_follow(&stack, &temp, instr, &size);
				i++;
			}
			if (ft_sorted(stack))
				ft_putendl("OK");
			else
				ft_putendl("KO");
		}
	}
	free(stack);
	free(temp);
	return (0);
}
