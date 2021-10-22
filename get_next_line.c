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

char	*end_line(char **buffer, int format)
{
	char	*ret;

	if (format < 0)
		return (*buffer);
	ret = ft_substr(*buffer, 0, format);
	free(*buffer);
	return (ret);
}

char	*read_line(int fd, char **buffer)
{
	char		curr_buffer[BUFFER_SIZE + 1];
	char		*tmp;
	char		*ret;
	int			nlpos;
	long int	i;

	ret = ft_strdup("");
	i = 0;
	tmp = NULL;
	ret = ft_strjoin(ret, *buffer);;
	tmp = ft_strchr(ret, '\n');
	while (!tmp)
	{
		i = read(fd, curr_buffer, BUFFER_SIZE);
		if (i <= 0)
			return (end_line(&ret, -1));
		curr_buffer[i] = '\0';
		ret = ft_strjoin(ret, curr_buffer);
		tmp = ft_strchr(ret, '\n');
	}
	nlpos = 0;
	while (ret[nlpos] != '\n')
		nlpos++;
	*buffer = ft_substr(ret, nlpos + 1, ft_strlen(ret) - nlpos);
	return (end_line(&ret, nlpos + 1));
}

char	*get_next_line(int fd)
{
	char	*ret;
	static char	*buffer[10];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[fd])
		buffer[fd] = ft_strdup("");
	ret = read_line(fd, buffer + fd);
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
