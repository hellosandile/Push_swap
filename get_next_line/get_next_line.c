/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samkhize <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:06:22 by samkhize          #+#    #+#             */
/*   Updated: 2019/07/13 07:00:02 by samkhize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_readline(char *start, char **line)
{
	size_t	i;
	char	*temp;

	i = 0;
	while (start[i] && start[i] != '\n')
		i++;
	*line = ft_strsub(start, 0, i);
	if ((temp = ft_strchr(start, '\n')) != NULL)
	{
		temp++;
		temp = ft_strdup(temp);
		free(start);
	}
	else
	{
		temp = ft_strdup("");
		free(start);
	}
	return (temp);
}

int		get_next_line(const int fd, char **line)
{
	static char	*raed;
	char		*temp;
	char		buf[BUFF_SIZE + 1];
	int			retu;

	if (read(fd, buf, 0) < 0 || fd < 0 || BUFF_SIZE < 1 || !line)
		return (-1);
	if (raed == NULL)
		raed = ft_strdup("");
	retu = 1;
	while (ft_strchr(raed, '\n') == NULL && retu != 0)
	{
		retu = read(fd, buf, BUFF_SIZE);
		if (raed == NULL)
			break ;
		buf[retu] = '\0';
		temp = raed;
		raed = ft_strjoin(raed, buf);
		free(temp);
	}
	if (retu == 0 && raed[0] == '\0')
		return (0);
	raed = ft_readline(raed, line);
	return (1);
}
