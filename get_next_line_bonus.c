/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalthaus <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:06:04 by yalthaus          #+#    #+#             */
/*   Updated: 2021/10/22 17:23:26 by yalthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*end_line(char **buffer, char *tmp, int format)
{
	char	*ret;

	if (format < 0)
	{
		if (!**buffer)
		{
			free(*buffer);
			*buffer = NULL;
			return (NULL);
		}
		ret = ft_strdup(*buffer);
		free(*buffer);
		*buffer = NULL;
		return (ret);
	}
	*buffer = ft_substr(*buffer, format + 1, ft_strlen(tmp));
	*(tmp + format + 1) = '\0';
	ret = tmp;
	tmp = NULL;
	return (ret);
}

char	*read_line(int fd, char **buffer, char *curr_buffer)
{
	char		*next_line;
	char		*tmp;
	int			nlpos;
	int	i;

	tmp = NULL;
	next_line = ft_strchr(*buffer, '\n');
	while (!next_line)
	{
		i = read(fd, curr_buffer, BUFFER_SIZE);
		if (i <= 0)
			return (end_line(buffer, tmp, -1));
		curr_buffer[i] = '\0';
		tmp = ft_strjoin(*buffer, curr_buffer);
		free(*buffer);
		*buffer = tmp;
		next_line = ft_strchr(*buffer, '\n');
	}
	nlpos = 0;
	tmp = *buffer;
	while (tmp[nlpos] != '\n')
		nlpos++;
	return (end_line(buffer, tmp, nlpos));
}

char	*get_next_line(int fd)
{
	char		*ret;
	static char	*buffer[4096];
	char		*curr_buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[fd])
		buffer[fd] = ft_strdup("");
	curr_buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!curr_buffer)
		return (NULL);
	ret = read_line(fd, buffer + fd, curr_buffer);
	free(curr_buffer);
	return (ret);
}
/*
int	main(int argc, char **argv)
{
	int	fd;
	int	i;

	(void)argc;
	i = 6;
	fd = open(argv[1], O_RDONLY);
	while (i--)
		printf("%s", get_next_line(fd));
}*/
