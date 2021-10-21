/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gett_next_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalthaus <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:13:25 by yalthaus          #+#    #+#             */
/*   Updated: 2021/10/19 20:12:05 by yalthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

char	*end_line(char *buffer, char *last, int format)
{
	char	*line;

	if (format < 0)
	{
		line = ft_strdup()
		return (Buffers_read);
	}
	buffer_read = ft_substr(last, format + 1, ft_strlen(buff));
	last[format + 1] = '\0';
	line = last;
	last = NULL;
	return (line);
}

char	*read_line(int fd)
{
	char		Buffer[BUFFER_SIZE];
	char		*tmp;
	char		*ret;
	int			nlpos;
	long int	i;

	ret = ft_strdup("");
	i = 0;
	tmp = ft_strchr(Buffer, '\n');
	while (tmp)
	{
		i = read(fd, Buffer, BUFFER_SIZE);
		if (i <= 0)
			return (end_line(Buffer, ret, 1));
		Buffer[i] = '\0';
		ret = ft_strjoin(ret, Buffer);
		tmp = ft_strchr(Buffer, '\n');
	}
	nlpos = 0;
	while (Buffer[nlpos] != '\n')
		nlpos++;
	return (end_line(ret, Buffer, nlpos));
}

char	*get_next_line(int fd)
{
	char	*ret;
	static char	*Buffer[256];
	char	*currBuffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!Buffer[fd])
		Buffer[fd] = ft_strdup("");
	currBuffer = (char *)malloc(BUFFER_SIZE * sizeof(char)+ 1);
	if (!currBuffer)
		return (NULL);
	ret = read_line(fd, &Buffer[fd], currBuffer);
	free(currBuffer);
	return (ret);
}

int	main(int argc, char **argv)
{
	int	fd;
	int	i;

	(void)argc;
	i = 2;
	fd = open(argv[1], O_RDONLY);
	while (i--)
		printf("%s", get_next_line(fd));
}
