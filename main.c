/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:17:37 by aestraic          #+#    #+#             */
/*   Updated: 2022/07/25 09:55:57 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <get_next_line.h>

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
	printf("LINE: %s", line);
	free(line);
	line = get_next_line(fd);
	printf("LINE: %s", line);
	free(line);
	// line = get_next_line(fd);
	// printf("LINE: %s", line);
	// free(line);
	// line = get_next_line(fd);
	// printf("LINE: %s", line);
	// free(line);
	// line = get_next_line(fd);
	// printf("LINE: %s", line);
	// free(line);
	// line = get_next_line(fd);
	// printf("LINE: %s", line);
	// free(line);
	// line = get_next_line(fd);
	// printf("LINE: %s", line);
	// free(line);
	// line = get_next_line(fd);
	// printf("LINE: %s", line);
	// free(line);
	// line = get_next_line(fd);
	// printf("LINE: %s", line);
	// free(line);
	// line = get_next_line(fd);
	// printf("LINE: %s", line);
	// free(line);
	// line = get_next_line(fd);
	// printf("LINE: %s", line);
	// free(line);


// 	//printf("\nBUFFER--------: %s", buffer);
system("leaks main.out");

}
