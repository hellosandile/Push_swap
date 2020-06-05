/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samkhize <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 14:08:22 by samkhize          #+#    #+#             */
/*   Updated: 2019/06/25 10:33:26 by samkhize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long int num)
{
	unsigned int	i;

	i = 0;
	if (num < 0)
	{
		num = num * -1;
		i++;
	}
	while (num >= 10)
	{
		num = num / 10;
		i++;
	}
	i++;
	return (i);
}

char		*ft_itoa(int n)
{
	unsigned int	i;
	char			*new;
	long int		num;

	i = ft_intlen(n);
	if (!(new = ft_strnew(i)))
		return (NULL);
	num = n;
	if (n < 0)
		num = num * -1;
	new[i] = '\0';
	i -= 1;
	while (num >= 10)
	{
		new[i] = (num % 10) + '0';
		num = num / 10;
		i -= 1;
	}
	new[i] = num + '0';
	i -= 1;
	if (n < 0)
		new[i] = '-';
	return (new);
}
