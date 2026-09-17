/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagrund <jagrund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 16:59:38 by jagrund           #+#    #+#             */
/*   Updated: 2026/09/17 21:01:16 by jagrund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*buffer;
	ssize_t			x;
	int				i;
	int				j;
	int				k;
	static char		*rest;
	char			*line;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	x = read(fd, buffer, BUFFER_SIZE);
	if (x == -1)
	{
		free(buffer);
		return (NULL);
	}
	buffer[x] = '\0';
	line = NULL;
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			line = malloc(i + 2);
			k = 0;
			while (k <= i)
			{
				line[k] = buffer[k];
				k++;
			}
			line[k] = '\0';
			j = i + 1;
			while (buffer[j])
				j++;
			rest = malloc(j - i);
			k = 0;
			while (buffer[i + 1])
			{
				rest[k] = buffer[i + 1];
				k++;
				i++;
			}
			rest [k] = '\0';
		}
		i++;
	}
	return (line);
}
