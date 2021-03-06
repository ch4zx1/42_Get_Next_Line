/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfischer <cfischer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 18:40:51 by cfischer          #+#    #+#             */
/*   Updated: 2022/04/23 18:41:03 by cfischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	c;

	c = 0;
	while (str[c] != '\0')
	{
		c++;
	}
	return (c);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != c)
	{
		if (*str == '\0')
		{
			return (NULL);
		}
		str++;
	}
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*s_start;
	char	*sub;
	char	*sub_iter;

	if (!s)
	{
		return (NULL);
	}
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (sub == NULL)
	{
		return (NULL);
	}
	s_start = (char *)s;
	s_len = ft_strlen(s);
	sub_iter = sub;
	s += start;
	while (((size_t)(s - s_start) < s_len) && len--)
	{
		*sub_iter++ = *s++;
	}
	*sub_iter = '\0';
	return (sub);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*pos;

	if (!s1 || !s2)
	{
		return (NULL);
	}
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
	{
		return (NULL);
	}
	pos = str;
	while (*s1)
	{
		*str++ = *s1++;
	}
	while (*s2)
	{
		*str++ = *s2++;
	}
	*str = '\0';
	return (pos);
}

char	*ft_strdup(const char *s1)
{
	char	*p;
	int		size;
	int		i;

	size = (int)ft_strlen(s1) + 1;
	p = malloc(size * sizeof(char));
	if (p == NULL)
	{
		return (NULL);
	}
	i = -1;
	while (++i < size)
	{
		p[i] = s1[i];
	}
	return (p);
}
