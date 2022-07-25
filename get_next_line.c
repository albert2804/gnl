/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:17:37 by aestraic          #+#    #+#             */
/*   Updated: 2022/07/25 11:32:04 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

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
	*buffer = ft_strjoin(*buffer, read_str, 0, 0);
	free(read_str);
	if (ft_strlen(*buffer) == 0 && ft_strlen(read_str) == 0)
	{
		*buffer = NULL;
	}
}

char	*make_new_buffer(char *read, int *a)
{
	char	*buffer;
	//int		pos;
	
	buffer = NULL;
	//pos = ft_check_for_newline_in_buffer(read);
	if (*a > 0)
	{
		buffer = ft_strdup(ft_strchr(read, '\n'));
		free(read);
	}
	else if (*a == 0 && ft_strlen(read) > 0)
	{
		
		buffer = NULL;
		free(read);
		//printf("\nREAD_BYTES:%d\n", *a);

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
	else if (buffer == NULL)
		return (NULL);
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
	static char	*buffer = NULL;
	int			a;

	line = NULL;
	a = 1;
	while (a > 0)
	{
		if (ft_check_for_newline_in_buffer(buffer) != -1)
			break ;
		read_into_buffer(fd, &buffer, &a);
		printf("BUFFER :%s\n", buffer);
		printf("BUFFER_ADRESSE :%p\n", buffer);
	}
	line = make_line(buffer);
	printf("%p\n", buffer);

	buffer = make_new_buffer(buffer, &a);
	return (line);
}
