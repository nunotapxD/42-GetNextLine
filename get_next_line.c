/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomas-a <ntomas-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:18:16 by ntomas-a          #+#    #+#             */
/*   Updated: 2024/11/05 16:18:16 by ntomas-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*str;

	str = NULL;
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
	{
		ft_null_buffer(buffer);
		return (NULL);
	}
	while (*buffer != 0 || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		str = ft_strjoin(str, buffer);
		if (ft_manage_buffer(buffer))
			break ;
	}
	return (str);
}

/* #include <fcntl.h>

int main()
{
	int fd = open("teste.txt", O_RDONLY);
	int fd2 = open("teste2.txt", O_RDONLY);
	char *line;
	
		line = get_next_line(fd);
		printf("%s", line);
		free (line);
 		line = get_next_line(fd2);
		printf("%s", line);
		free (line);

	return 0;
} */