/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:17:37 by aestraic          #+#    #+#             */
/*   Updated: 2022/07/26 14:17:31 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *s)
{
	int		n;
	int		i;
	char	*s_cpy;

	i = 0;
	n = ft_strlen(s);
	s_cpy = malloc(n * sizeof(char) + 1);
	if (!s_cpy)
	{
		free(s);
		return (NULL);
	}
	if (s == NULL)
	{
		free (s);
		return (NULL);
	}
	while (i <= n)
	{
		s_cpy[i] = s[i];
		i++;
	}
	return (s_cpy);
}

void	read_into_buffer(int fd, char **buffer, int *a)
{
	char	*read_str;

	read_str = malloc(BUFFER_SIZE * sizeof(char) + 1);
	*a = read(fd, read_str, BUFFER_SIZE);
	read_str[*a] = '\0';
	if (*a > 0)
		*buffer = ft_strjoin(*buffer, read_str, -1, -1);
	free(read_str);
}

char	*make_new_buffer(char *read, int *a)
{
	char	*buffer;

	buffer = NULL;
	if (*a > 0)
	{
		buffer = ft_strdup(ft_strchr(read, '\n'));
		free(read);
	}
	else if (*a == 0 && ft_strlen(read) > 0)
	{
		buffer = NULL;
		free(read);
	}
	return (buffer);
}

char	*make_line(char *buffer)
{
	char	*line;
	int		i;
	int		pos;

	line = NULL;
	pos = ft_check_for_newline_in_buffer(buffer);
	if (pos == -1 && buffer != NULL)
	{
		line = ft_strdup(buffer);
		return (line);
	}
	line = malloc(sizeof(char) * pos + 1);
	i = 0;
	while (i < pos)
	{
		line[i] = buffer[i];
		i ++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer[4096];
	int			a;

	line = NULL;
	a = 1;
	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	while (a > 0)
	{
		if (ft_check_for_newline_in_buffer(buffer[fd]) != -1)
			break ;
		read_into_buffer(fd, &buffer[fd], &a);
		if (ft_strlen(buffer[fd]) == 0 && buffer[fd])
			free (buffer[fd]);
	}
	if (a == 0 && ft_strlen(buffer[fd]) == 0)
		return (line);
	line = make_line(buffer[fd]);
	buffer[fd] = make_new_buffer(buffer[fd], &a);
	return (line);
}
