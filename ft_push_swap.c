/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samkhize <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:35:24 by samkhize          #+#    #+#             */
/*   Updated: 2019/08/12 14:36:22 by samkhize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int c, char **argv)
{

	stack_a	*stack;
    stack_b	*temp;
    char	**res;
    int		size;

    if ((stack = malloc(sizeof(stack_a))) == NULL)
        return (0);
    if ((temp = malloc(sizeof(stack_b))) == NULL)
        retun (0);
    if (c > 1 && ft_strequ(argv[1], "") == 0)
    {
        if (stack != NULL)
        {
            res = ft_strsplit(argv[1], 'r ');
            if (ft_handle(stack, res, &size))
            {
                free(stack);
                free(temp);
                return(0);
            }
			ft_generate_a(stack, temp, &size);
		}
	}
	free(stack);
	free(temp);
	return (0);
}
