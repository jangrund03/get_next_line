/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majid <majid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 20:02:01 by jagrund           #+#    #+#             */
/*   Updated: 2026/10/03 15:34:46 by majid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str) // ft_strlen
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

char	*dup_string(char *s) // ft_strdup
{
	char	*copy;
	size_t	i;

	if (!s)
		return (NULL);
	copy = malloc(ft_strlen(s) + 1);
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

char	*join_strings(char *s1, char *s2) // ft_strjoin
{
	char	*str;
	size_t	len1;
	size_t	len2;
	size_t	i;

	if (!s1)
		return (dup_string(s2));
	if (!s2)
		return (dup_string(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
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
	int		len;
	char	*newstash;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	len = i;
	if (stash[i] == '\n')
		len++;
	newstash = malloc(len + 1);
	if (!newstash)
		return (NULL);
	i = 0;
	while (i < len)
	{
		newstash[i] = stash[i];
		i++;
	}
	newstash[len] = '\0';
	return (newstash);
}

char	*make_rest(char *stash)
{
	int		i;
	int		k;
	char	*rest;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] != '\n' || stash[i + 1] == '\0')
		return (NULL);
	rest = malloc(ft_strlen(stash + i + 1) + 1);
	if (!rest)
		return (NULL);
	k = 0;
	i++;
	while (stash[i])
		rest[k++] = stash[i++];
	rest[k] = '\0';
	return (rest);
}
