/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:17:37 by aestraic          #+#    #+#             */
/*   Updated: 2022/07/13 13:04:02 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <get_next_line.h>

void	ft_free(void *ptr)
{
	if (ptr)
		free(ptr);
	else
		ptr = NULL;
}

char	*read_into_buffer(int fd, char *buffer)
{
	int		a;
	char	*buffer_ret;
	char	*read_str;

	read_str = malloc(BUFFER_SIZE * sizeof(char));
	a = read(fd, read_str, BUFFER_SIZE);
	buffer_ret = ft_strjoin(buffer, read_str);
	free (buffer);
	free (read_str);
	return (buffer_ret);
}

char	*make_new_buffer(char *read)
{
	char	*buffer;

	buffer = ft_strchr(read, '\n');
	return (buffer);
}

char	*make_line(char *buffer)
{
	char	*line;
	int		i;
	int		pos;

	pos = ft_check_pos_of_nline_in_buffer(buffer);
	i = 0;
	line = malloc(sizeof(char) * pos);
	while (i < pos)
	{
		line[i] = buffer[i];
		i ++;
	}
	free (buffer);
	return (line);
}

char	*get_next_line1(int fd)
{
	int			a;
	char		*line;
	static char	*buffer;

	a = 0;
	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	while (1)
	{
		buffer = read_into_buffer(fd, buffer);
		if (ft_check_for_newline_in_buffer(buffer) == 1)
			break ;
	}
	line = make_line(buffer);
	buffer = make_new_buffer(buffer);
	return (line);
}

int	main(void)
{
	static char	*buffer = NULL;
	char		*line;
	int fd = 0;


	buffer = "get\n\n\nnext";
	fd = open("text.txt", O_RDONLY);
	line = get_next_line1(fd);
	ft_printf("LINE: %s", line);
	line = get_next_line1(fd);
	ft_printf("LINE: %s", line);
	//ft_printf("\nBUFFER--------: %s", buffer);
	//system("leaks main.out");

}

// int main(void)
// {

// 	int fd;
// 	int i = 0;
// 	// char *buffer_tmp = NULL;
// 	// char *buffer_read = NULL;

// 	fd = open("text.txt", O_RDONLY);
// 	printf("FD: %d\n--------\n", fd);

// 	char *line;
// 	while(i < 11)
// 	{
// 	line = get_next_line(fd);
// 	printf("|%d: %s",i++, line);
// 	free(line);
// 	//i++;
// 	//buffer_tmp = ft_strjoin(buffer_tmp, buffer_read);
// 	//printf("\nBFT%s\n", buffer_tmp);
// 	}
// 	//system("leaks a.out");
// }
