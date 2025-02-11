/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femullao <femullao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:49:16 by femullao          #+#    #+#             */
/*   Updated: 2024/11/11 20:08:59 by femullao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_readline(char *b, int fd)
{
	char	*bi;
	int		rd;

	rd = 1;
	if (!b)
	{
		b = malloc(sizeof(char) * 1);
		if (!b)
			return (NULL);
		b[0] = '\0';
	}
	bi = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!bi)
		return (NULL);
	while (!ft_strchr_gnl(b, '\n') && rd != 0)
	{
		rd = read(fd, bi, BUFFER_SIZE);
		if (rd == -1)
			return (free(b), free(bi), NULL);
		bi[rd] = '\0';
		b = ft_strjoin_gnl(b, bi);
	}
	free (bi);
	return (b);
}

char	*get_f_line(char *b)
{
	char	*bi;
	size_t	i;

	i = 0;
	if (!*b)
		return (NULL);
	while (b[i] && b[i] != '\n')
		i++;
	if (b[i] == '\n')
		i++;
	bi = malloc(sizeof(char) * (i + 1));
	if (!bi)
		return (NULL);
	i = -1;
	while (b[++i] && b[i] != '\n')
		bi[i] = b[i];
	if (b[i] == '\n')
		bi[i++] = '\n';
	bi[i] = '\0';
	return (bi);
}

char	*get_ot_line(char *b)
{
	char	*r;
	size_t	i;
	size_t	j;

	i = 0;
	while (b[i] && b[i] != '\n')
		i++;
	if (b[i] == '\0')
		return (free(b), NULL);
	if (b[i] == '\n')
		i++;
	r = malloc(sizeof(char) * ft_strlen_gnl(b) - i + 1);
	if (!r)
		return (free(b), NULL);
	j = 0;
	while (b[i])
		r[j++] = b[i++];
	r[j] = '\0';
	free(b);
	return (r);
}

char	*get_next_line(int fd)
{
	static char	*buf[10240];
	char		*r;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf[fd] = ft_readline(buf[fd], fd);
	if (!buf[fd])
		return (NULL);
	r = get_f_line(buf[fd]);
	buf[fd] = get_ot_line(buf[fd]);
	return (r);
}
