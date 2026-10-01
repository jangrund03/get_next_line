/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagrund <jagrund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 16:59:38 by jagrund           #+#    #+#             */
/*   Updated: 2026/10/01 21:24:25 by jagrund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	has_newline(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*read_to_stash(int fd, char *stash)
{
	char	*buffer;
	ssize_t	bytes;
	char	*tmp;

	bytes = 1;
	buffer = malloc(BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	while (has_newline(stash) == 0 && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE - 1);
		if (bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		tmp = join_strings (stash, buffer);
		if (!tmp)
			return (NULL);
		free(stash);
		stash = tmp;
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{

}
