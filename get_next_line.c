/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:17:37 by aestraic          #+#    #+#             */
/*   Updated: 2022/07/20 16:56:35 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

char	*ft_strdup(const char *s)
{
	int		n;
	int		i;
	char	*s_cpy;

	i = 0;
	n = ft_strlen((char *)s);
	s_cpy = (char *)malloc(n * sizeof(char) + 1);
	if (!s_cpy)
		return (NULL);
	while (i <= n)
	{
		s_cpy[i] = s[i];
		i++;
	}
	return (s_cpy);
}

char	*read_into_buffer(int fd, char *buffer, int *a)
{
	char	*buffer_ret;
	char	*read_str;

	read_str = malloc(BUFFER_SIZE * sizeof(char) + 1);
	*a = read(fd, read_str, BUFFER_SIZE);
	buffer_ret = NULL;
	read_str[*a] = '\0';
	buffer_ret = ft_strjoin(buffer, read_str);
	free (read_str);
	free (buffer);
	return (buffer_ret);
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
	else if (*a == 0)
	{
		free(buffer);
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
	pos = ft_check_pos_of_nline_in_buffer(buffer);
	i = 0;
	if (ft_check_for_newline_in_buffer(buffer) == 1)
	{
		line = malloc(sizeof(char) * pos + 1);
		while (i < pos)
		{
			line[i] = buffer[i];
			i ++;
		}
		line[i] = '\0';
	}
	else if (ft_check_for_newline_in_buffer(buffer) == 0)
	{
		free(line);
		return (buffer);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;
	int			a;

	a = 1;
	while (a > 0)
	{
		if (ft_check_for_newline_in_buffer(buffer) == 1)
			break ;
		buffer = read_into_buffer(fd, buffer, &a);
	}
	line = make_line(buffer);
	buffer = make_new_buffer(buffer, &a);
	if (a == 0)
	{
		free(buffer);
		return (NULL);
	}
	else
		return (line);
}
