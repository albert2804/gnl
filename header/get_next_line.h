/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:26:10 by aestraic          #+#    #+#             */
/*   Updated: 2022/07/25 09:56:22 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 20
# endif

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <stdio.h>


char	*get_next_line(int fd);
size_t	ft_strlen(char *c);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2, int i, int j);
int		ft_check_for_newline_in_buffer(char *buffer);
//int		ft_check_pos_of_nline_in_buffer(char *buffer);
char	*make_line(char	*buffer);
char	*make_new_buffer(char *read, int *a);
void	read_into_buffer(int fd, char **buffer_ret, int *a);
char	*ft_strdup(char *s);
#endif