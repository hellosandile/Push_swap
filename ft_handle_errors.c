/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samkhize <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:30:32 by samkhize          #+#    #+#             */
/*   Updated: 2019/08/13 15:37:18 by samkhize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_handle(stack_a *head, char **stack, int *size)
{
	if (ft_check(stack))
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	ft_populate(head, stack, size);
	if (ft_dup(head))
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	return (0);
}

char		*ft_instr(char *str)
{
	return (ft_strsub(str, 1, ft_strlen(str)));
}

int			ft_handle_instr(char *instr)
{
	if (ft_exist(instr))
		return (0);
	return (1);
}