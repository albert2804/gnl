/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:17:37 by aestraic          #+#    #+#             */
/*   Updated: 2022/07/19 19:04:14 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <get_next_line.h>

// void	ft_free(void *ptr)
// {
// 	if (ptr)
// 		free(ptr);
// 	ptr = NULL;	
// }

// char	*read_into_buffer(int fd, char *buffer)
// {
// 	//int		a;
// 	char	*buffer_ret;
// 	char	*read_str;

// 	//buffer = malloc(0);
// 	read_str = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
// 	//a = read(fd, read_str, BUFFER_SIZE);
// 	read(fd, read_str, BUFFER_SIZE);
// 	// ft_printf("READ: %s\n", read_str);
// 	buffer_ret = ft_strjoin(buffer, read_str);
// 	//ft_free (buffer);
// 	ft_free (read_str);
// 	return (buffer_ret);
// }

// char	*make_new_buffer(char *read)
// {
// 	char	*buffer;

// 	buffer = ft_strchr(read, '\n');
// 	return (buffer);
// }

// char	*make_line(char *buffer)
// {
// 	char	*line;
// 	int		i;
// 	int		pos;

// 	pos = ft_check_pos_of_nline_in_buffer(buffer);
// 	i = 0;
// 	line = ft_calloc(sizeof(char), pos + 1);
// 	while (i < pos)
// 	{
// 		line[i] = buffer[i];
// 		i ++;
// 	}
// 	//free (buffer);
// 	line[i] = '\0';
// 	return (line);
// }

// char	*get_next_line(int fd)
// {
// 	char		*line;
// 	static char	*buffer = NULL;

// 	if (!buffer)
// 	{
// 		buffer = malloc(sizeof(char) * BUFFER_SIZE);
// 	}
// 	//ft_printf("R0Buffer: %s\n", buffer);
// 	while (1)
// 	{
// 		if (ft_check_for_newline_in_buffer(buffer) == 1)
// 		{
// 			break ;
// 		}
// 		buffer = read_into_buffer(fd, buffer);
// 		// ft_printf("READ_Buffer: %s\n", buffer);
// 	}
// 	line = make_line(buffer);
// 	//ft_printf("BEFORE_Buffer: %s\n", buffer);
// 	// ft_printf("LINE: %s\n", line);
// 	buffer = make_new_buffer(buffer);
// 	//free(buffer);
// 	//ft_printf("-----\nCHECK_NBUFFER: %d\n-----\n", ft_check_for_newline_in_buffer(buffer));
// 	//ft_printf("AFTER_Buffer: %s\n", buffer);
// 	return (line);
// }

int	main(void)
{
	//static char	*buffer;
	char		*line;
	int fd = 0;


	//buffer = "get\n\n\nnext";
	fd = open("text_alpha.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("LINE: %s", line);
	free(line);
	line = get_next_line(fd);
	ft_printf("LINE: %s", line);
	free(line);
	line = get_next_line(fd);
	ft_printf("LINE: %s", line);
	free(line);
	line = get_next_line(fd);
	ft_printf("LINE: %s", line);
	free(line);
	line = get_next_line(fd);
	ft_printf("LINE: %s", line);
	free(line);
	line = get_next_line(fd);
	ft_printf("LINE: %s", line);
	free(line);
	line = get_next_line(fd);
	ft_printf("LINE: %s", line);
	free(line);
	line = get_next_line(fd);
	ft_printf("LINE: %s", line);
	free(line);
	line = get_next_line(fd);
	ft_printf("LINE: %s", line);
	free(line);
	line = get_next_line(fd);
	ft_printf("LINE: %s", line);
	free(line);
	line = get_next_line(fd);
	ft_printf("LINE: %s", line);
	free(line);
	// line = get_next_line(fd);
	// ft_printf("LINE: %s", line);
	// free(line);
	// line = get_next_line(fd);
	// ft_printf("LINE: %s", line);
	// ft_free(line);

	//ft_printf("\nBUFFER--------: %s", buffer);
	//system("leaks main.out");

}
