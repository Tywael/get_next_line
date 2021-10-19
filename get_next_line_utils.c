/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalthaus <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:14:21 by yalthaus          #+#    #+#             */
/*   Updated: 2021/10/19 20:12:07 by yalthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	while (*s && (char)c != *s)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

char	*ft_strdup(char *s1)
{
	int		i;
	int		len;
	char	*s;

	i = 0;
	len = ft_strlen((char *)s1);
	s = (char *)malloc((len + 1) * sizeof(char));
	if (s == (void *)0)
		return ((void *)0);
	while (i < len)
	{
		*(s + i) = *(s1 + i);
		i++;
	}
	*(s + i) = '\0';
	return (s);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	j = 0;
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (*(s1 + i))
	{
		*(str + i) = *(s1 + i);
		i++;
	}
	while (*(s2 + j))
	{
		*(str + i + j) = *(s2 + j);
		j++;
	}
	*(str + i + j) = '\0';
	return (str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (i < len)
	{
		*(str + i) = *(s + start + i);
		i++;
	}
	*(str + i) = '\0';
	return (str);
}
