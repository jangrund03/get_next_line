/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagrund <jagrund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 17:33:42 by jagrund           #+#    #+#             */
/*   Updated: 2026/10/01 21:28:53 by jagrund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>


char	*get_next_line(int fd);
int		count_len(char	*str);
char	*dup_string(char *s);
char	*join_strings(char *s1, char *s2);
char	*make_line(char *stash);
char	*make_rest(char *stash);
char	*read_to_stash(int fd, char *stash);

#endif
