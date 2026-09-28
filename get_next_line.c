/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagrund <jagrund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 16:59:38 by jagrund           #+#    #+#             */
/*   Updated: 2026/09/28 19:58:56 by jagrund          ###   ########.fr       */
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
	int				found;
	static char		*rest;
	char			*stash;
	char			*line;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	found = 0;
	x = 1;
	while (found == 0 && x != 0)
	{
		stash = NULL;
		x = read(fd, buffer, BUFFER_SIZE);
		if (x == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[x] = '\0';
		i = 0;
		while (buffer[i])
		{
			if (buffer[i] == '\n')
				found = 1;
			i++;
		}
	}
	line = NULL;
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			found = 1;
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
