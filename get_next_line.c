/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:17:37 by aestraic          #+#    #+#             */
/*   Updated: 2022/07/20 15:31:02 by aestraic         ###   ########.fr       */
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
	buffer_ret = NULL;
	//read(fd, read_str, BUFFER_SIZE);
	read_str[a] = '\0';
	ft_printf("READ_BYTES: %d\n", a);
	if (a != 0)
	{
		buffer_ret = ft_strjoin(buffer, read_str);
		free (read_str);
		free (buffer);
	}
	else if (a == 0)
		return (buffer_ret);
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
	if (ft_check_for_newline_in_buffer(buffer) == 1)
		{
			while (i < pos)
		{
			line[i] = buffer[i];
			i ++;
		}
		line[i] = '\0';

	}
	else if (ft_check_for_newline_in_buffer(buffer) ==  0)
	{	
		return (buffer);
	}
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
	ft_printf("Buffer_start: %s\n", buffer);
	if (buffer == NULL)
		return (buffer);
	while (1)
	{
		ft_printf("CHECK :%d\n",ft_check_for_newline_in_buffer(buffer));
		ft_printf("LENGTH :%d\n",ft_strlen(buffer));
		
		if (ft_check_for_newline_in_buffer(buffer) == 1)
			break ;
		buffer = read_into_buffer(fd, buffer);
		// ft_printf("%s", buffer);
		if (buffer == NULL)
			return (buffer);
			//return (NULL);
		// ft_printf("LOOP_Buffer: %s\n", buffer);
	}
	line = make_line(buffer);
	// ft_printf("OLD_Buffer: %s\n", buffer);
	buffer = make_new_buffer(buffer);
	ft_printf("NEWBUFFER_END: %s\n", buffer);
	
	//free(buffer);
	//ft_printf("-----\nCHECK_NBUFFER: %d\n-----\n", ft_check_for_newline_in_buffer(buffer));
	// ft_printf("NEW_Buffer: %s\n", buffer);
	// ft_printf("LINE: %s\n", line);
	return (line);
}
