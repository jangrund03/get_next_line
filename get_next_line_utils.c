/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagrund <jagrund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 20:02:01 by jagrund           #+#    #+#             */
/*   Updated: 2026/09/28 20:59:44 by jagrund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	count_len(char	*str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

char	*dup_string(char *s)
{
	char	*copy;
	size_t	i;

	if (!s)
		return (NULL);
	copy = malloc(count_len(s) + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*join_strings(char *s1, char *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;
	size_t	i;

	if (!s1)
		return (dup_string(s2));
	if (!s2)
		return (dup_string(s1));
	len1 = count_len(s1);
	len2 = count_len(s2);
	str = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[i - len1])
	{
		str[i] = s2[i - len1];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*make_line(char *stash)
{
	int		i;
	int		j;
	char	*newstash;

	i = 0;
	j = 0;
	while (stash[i])
	{
		if (stash[i] == '\n')
		{
			newstash = malloc(i + 2);
			while (j <= i)
			{
				newstash[j] = stash[j];
				j++;
			}
			newstash[j] = '\0';
			return (newstash);
		}
		if (stash[i] == '\0')
		{
			newstash = malloc(i);
			while (j <= i)
			{
				newstash[j] = stash[j];
				j++;
			}
			newstash[j] = '\0';
			return (newstash);
		}
		i++;
	}
}
