/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:17:37 by aestraic          #+#    #+#             */
/*   Updated: 2022/07/20 16:59:43 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <get_next_line.h>

size_t	ft_strlen(const char *c)
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
char	*ft_strchr(const char *s, int c)
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		size_dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s2 && s1)
		return (ft_strdup(s1));
	size_dest = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * size_dest + 1);
	if (!str || (!s1 && !s2))
		return (NULL);
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
	str[i + j] = '\0';
	return (str);
}

/*
check if there is an occurence of a \\n.
Returns 1 for a found \\n, 0 for none
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
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_pos_of_nline_in_buffer(char *buffer)
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
	return (i);
}
