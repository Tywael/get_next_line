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

char	*read_line(int fd)
{
	char			Buffer[BUFFER_SIZE];
	char			*tmp;
	char			*ret;
	static int		len;
	int				i;

	ret = ft_strdup("");
	len = 0;
	tmp = NULL;
	if (len % BUFFER_SIZE)
		return (NULL);
	while (!tmp)
	{
		len += read(fd, Buffer, BUFFER_SIZE);
		tmp = ft_strchr(((char *)Buffer + len), '\n');
		i = tmp - (Buffer + len);
		ret = ft_strjoin(ret, ft_substr((Buffer + len), 0, i));
		if (!tmp && len % BUFFER_SIZE)
			return (ret);
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	char	*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ret = read_line(fd);
	if (!ret)
		return (NULL);
	return (ret);
}

int	main(int argc, char **argv)
{
	int	fd;
	int	i;

	(void)argc;
	i = 1;
	fd = open(argv[1], O_RDONLY);
	while (i--)
		printf("%s\n", get_next_line(fd));
}
