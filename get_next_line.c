/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majid <majid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 16:59:38 by jagrund           #+#    #+#             */
/*   Updated: 2026/10/03 15:59:09 by majid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free_and_null(char **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return (NULL);
}

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

static char	*read_chunk(int fd, char *stash, char *buffer, ssize_t *bytes)
{
	char	*tmp;

	*bytes = read(fd, buffer, BUFFER_SIZE);
	if (*bytes < 0)
		return (free_and_null(&stash));
	buffer[*bytes] = '\0';
	if (*bytes == 0)
		return (stash);
	tmp = join_strings(stash, buffer);
	if (!tmp)
		return (free_and_null(&stash));
	free(stash);
	return (tmp);
}

char	*read_to_stash(int fd, char *stash)
{
	char	*buffer;
	ssize_t	bytes;

	if (BUFFER_SIZE <= 0)
		return (free_and_null(&stash));
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (free_and_null(&stash));
	bytes = 1;
	while (!has_newline(stash) && bytes > 0)
	{
		stash = read_chunk(fd, stash, buffer, &bytes);
		if (!stash && bytes != 0)
			return (free_and_null(&buffer));
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*rest;
	size_t		line_len;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free_and_null(&stash));
	stash = read_to_stash(fd, stash);
	if (!stash || !*stash)
		return (free_and_null(&stash));
	line = make_line(stash);
	if (!line)
		return (free_and_null(&stash));
	line_len = ft_strlen(line);
	rest = make_rest(stash);
	if (line[line_len - 1] == '\n' && stash[line_len] && !rest)
	{
		free(line);
		return (free_and_null(&stash));
	}
	free(stash);
	stash = rest;
	return (line);
}
