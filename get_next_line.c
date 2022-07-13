/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:17:37 by aestraic          #+#    #+#             */
/*   Updated: 2022/07/07 16:43:44 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

char *get_next_line(int fd)
{
	char buffer_read[BUFFER_SIZE + 1];
	static char *buffer_tmp = "";
	char *line;
	int read_line;
	int pos;
	int value_nl;
	
	read_line = 1;
	if (buffer_tmp == (char *) '0' || (fd < 0 || BUFFER_SIZE <= 0))
	{
		//free (buffer_tmp);
		return NULL;
	}
	//printf("READLINE VOR WHILE: %d\n", read_line);
	//while (read_line > 0)// && ft_strlen(buffer_tmp) > 0)
	while (read_line > 0)// && ft_strlen(buffer_tmp) > 0)
	{
		read_line = read(fd, buffer_read, BUFFER_SIZE);
		//printf("\nREADLINE in WHILE: %d\n", read_line);
		buffer_read[BUFFER_SIZE] = '\0';
		if (read_line < BUFFER_SIZE)
			buffer_read[read_line] = '\0';
		//printf("\nBUFFER_READ: %s", buffer_read);
		//char *tmp = buffer_tmp;
		buffer_tmp = ft_strjoin(buffer_tmp, buffer_read);
		// if (tmp != 0)
		// 	free (tmp);
		value_nl = ft_check_for_newline_in_buffer(buffer_tmp);
		//printf("\n---BUFFER_TMP\n%s\n----\n", buffer_tmp);
		if (value_nl == 1)
		{
			pos = ft_check_pos_of_nline_in_buffer(buffer_tmp);
			line = ft_write_line(pos, buffer_tmp);
			buffer_tmp = ft_strchr(buffer_tmp, '\n');
			return(line);
		}
		else if (value_nl == 0 && read_line < BUFFER_SIZE)
		{
			//printf("\nVALUE");
			pos = ft_strlen(buffer_tmp);
			//printf("%d", pos);
			line = ft_write_line(pos, buffer_tmp);
			buffer_tmp = (char *)'0';
			return (line);
		}
	}
	return (buffer_tmp);
}

