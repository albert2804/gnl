/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:17:37 by aestraic          #+#    #+#             */
/*   Updated: 2022/07/19 18:50:24 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

char	*read_into_buffer(int fd, char *buffer)
{
	int		a;
	char	*buffer_ret;
	char	*read_str;

	//buffer = malloc(0);
	read_str = malloc(BUFFER_SIZE * sizeof(char) + 1);
	a = read(fd, read_str, BUFFER_SIZE);
	// ft_printf("\nREADBYTES:%d\n", a);
	//buffer_ret = NULL;
	//read(fd, read_str, BUFFER_SIZE);
	read_str[BUFFER_SIZE] = '\0';
	//ft_printf("READ: %s\n", read_str);
	buffer_ret = ft_strjoin(buffer, read_str);
	free (read_str);
	free (buffer);
	return (buffer_ret);
}

char	*make_new_buffer(char *read)
{
	char	*buffer;
	
	buffer = ft_strdup(ft_strchr(read, '\n'));
	free(read);
	return (buffer);
}

char	*make_line(char *buffer)
{
	char	*line;
	int		i;
	int		pos;

	pos = ft_check_pos_of_nline_in_buffer(buffer);
	i = 0;
	line = malloc(sizeof(char) * pos + 1);
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
	static char	*buffer;

	if (!buffer)
	{
		buffer = malloc(1 * sizeof(char) + 1);
		buffer[0] = '\0';
	}
	// ft_printf("R0Buffer: %s\n", buffer);
	while (1)
	{
		if (ft_check_for_newline_in_buffer(buffer) == 1)
			break ;
		buffer = read_into_buffer(fd, buffer);
		// if (buffer == NULL)
		// 	return (buffer);
		//ft_printf("%s", buffer);
		// if (buffer == NULL)
		// 	return (buffer);
			//return (NULL);
		// ft_printf("LOOP_Buffer: %s\n", buffer);
	}
	line = make_line(buffer);
	
	// ft_printf("OLD_Buffer: %s\n", buffer);
	buffer = make_new_buffer(buffer);
	
	//free(buffer);
	//ft_printf("-----\nCHECK_NBUFFER: %d\n-----\n", ft_check_for_newline_in_buffer(buffer));
	// ft_printf("NEW_Buffer: %s\n", buffer);
	// ft_printf("LINE: %s\n", line);
	return (line);
}
