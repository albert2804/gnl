/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:17:37 by aestraic          #+#    #+#             */
/*   Updated: 2022/07/25 11:23:58 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <get_next_line.h>

size_t	ft_strlen(char *c)
{
	size_t	count;

	count = 0;
	if (c == NULL)
		return (0);
	while (c[count] != '\0')
	{
		count++;
	}
	return (count);
}

/*
updated strchr. changed a + 1 in the return value.
*/
char	*ft_strchr(char *s, int c)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s);
	while (s[i] != (const char)c)
	{
		if (i == len)
		{
			return ((char *)s);
		}
		i++;
	}
	return ((char *)s + i + 1);
}

char	*ft_strjoin(char *s1, char *s2, int i, int j)
{
	char	*str;

	if (!s2 && s1)
		return (ft_strdup(s1));
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!str || (!s1 && !s2))
	{	
		return (NULL);
	}
	while (i < (int) ft_strlen(s1))
	{
		str[i] = s1[i];
		i++;
	}
	while (j < (int) ft_strlen(s2))
	{
		str[i + j] = s2[j];
		j++;
	}
	if (s1)
		free (s1);
	printf("ADRESSEinSTRJOIN: %p\n", str);
	printf("String: %s\n", str);
	str[i + j] = '\0';
	return (str);
}

/*
check if there is an occurence of a \\n.
Returns 1 for a found \\n, 0 for none
Merge ft_check_for_newline_in_buffer && ft_check_pos_of_nline_in_buffer
*/
int	ft_check_for_newline_in_buffer(char *buffer)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(buffer);
	while (i < len)
	{
		if (buffer[i] == '\n')
			return (i + 1);
		i++;
	}
	return (-1);
}
