/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samkhize <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 09:52:29 by samkhize          #+#    #+#             */
/*   Updated: 2019/07/16 12:42:54 by samkhize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include <fcntl.h>

int		main(int c, char **v)
{
	char **numbers;
	char *buffer;
	int i;

	i = 0;

	buffer = (char *)malloc(sizeof(char) * 5);
	if (c > 1)
	{
		numbers = ft_strsplit(v[1], ' ');
		while (numbers[i])
		{
		if (ft_atoi(numbers[i]))
			ft_putendl("Success");
		else
		{
			ft_putendl("Error");
			return (0);
		}
		i++;
		}
		/*while (read(0, buffer, 4) > 0)
		{
			if (ft_strequ(buffer, "sa"))
				ft_putendl("Exists");
			else
				ft_putendl("Doesn't");
		}*/
		i = 0;
		while (numbers[i])
		{
			if (ft_strcmp(ft_itoa(ft_atoi(numbers[i])), numbers[i]) != 0)
			{
				ft_putendl("Error after strcmp");
				return (0);
			}
		i++;
		}
	}
	return (0);
}
