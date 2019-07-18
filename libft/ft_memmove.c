/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samkhize <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 13:13:32 by samkhize          #+#    #+#             */
/*   Updated: 2019/06/12 14:43:23 by samkhize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*charsrc;
	unsigned char	*chardst;
	size_t			i;

	if (src == dst)
		return (dst);
	charsrc = (unsigned char *)src;
	chardst = (unsigned char *)dst;
	if (src < dst)
	{
		i = len;
		while (i-- > 0)
			chardst[i] = charsrc[i];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			chardst[i] = charsrc[i];
			i++;
		}
	}
	return (dst);
}
