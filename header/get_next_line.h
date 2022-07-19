/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:26:10 by aestraic          #+#    #+#             */
/*   Updated: 2022/07/19 18:19:21 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
#define FT_GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 20
#endif

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <libft.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *c);
char	*ft_strchr(const char *s, int c);
char *ft_strjoin(char const *s1, char const *s2);
int ft_check_for_newline_in_buffer(char *buffer);
int ft_check_pos_of_nline_in_buffer(char *buffer);
char	*make_line(char *buffer);
char	*make_new_buffer(char *read);
char	*read_into_buffer(int fd, char *buffer);
char	*ft_strdup(const char *s);


#endif