/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfischer <cfischer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 18:40:36 by cfischer          #+#    #+#             */
/*   Updated: 2022/04/23 19:21:25 by cfischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*join_line(int nlp, char	**buffer)
{
	char	*tmp;
	char	*res;

	if (nlp <= 0)
	{
		if (**buffer == 0)
		{
			free(*buffer);
			*buffer = NULL;
			return (NULL);
		}
		res = *buffer;
		*buffer = NULL;
		return (res);
	}
	tmp = ft_substr(*buffer, nlp, BUFFER_SIZE);
	res = *buffer;
	res[nlp] = 0;
	*buffer = tmp;
	return (res);
}

char	*read_line(int fd, char	**buffer, char	*tmp)
{
	int		nbytes;
	char	*nl;
	char	*nstr;

	nbytes = 0;
	nstr = NULL;
	nl = ft_strchr(*buffer, '\n');
	while (nl == NULL)
	{
		nbytes = read(fd, tmp, BUFFER_SIZE);
		if (nbytes <= 0)
		{
			return (join_line(nbytes, buffer));
		}
		tmp[nbytes] = 0;
		nstr = ft_strjoin(*buffer, tmp);
		free(*buffer);
		*buffer = nstr;
		nl = ft_strchr(*buffer, '\n');
	}
	return (join_line(nl - *buffer + 1, buffer));
}

char	*get_next_line(int fd)
{
	char		*tmp;
	char		*res;
	static char	*buffer[256];

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (tmp == NULL)
	{
		return (NULL);
	}
	if (!buffer[fd])
	{
		buffer[fd] = ft_strdup("");
	}
	res = read_line(fd, &buffer[fd], tmp);
	free (tmp);
	return (res);
}
