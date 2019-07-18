/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samkhize <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 10:58:03 by samkhize          #+#    #+#             */
/*   Updated: 2019/06/24 10:33:23 by samkhize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	size_t	cnt;

	cnt = 0;
	if (s1 == s2)
		return (1);
	if (!s1 || !s2)
		return (0);
	while (s1[cnt] && s1[cnt] == s2[cnt])
		cnt++;
	if (s1[cnt] == s2[cnt])
		return (1);
	return (0);
}
