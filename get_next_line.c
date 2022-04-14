/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfischer <cfischer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:24:35 by cfischer          #+#    #+#             */
/*   Updated: 2022/04/13 21:58:55 by cfischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *join_line(int nlp, char** buffer)
{
    char* tmp;
    char* res;

    tmp = ft_substr(*buffer, nlp, BUFFER_SIZE);
    res = *buffer;
    res[nlp] = 0;
    *buffer = tmp;

    return res;
}

char *read_line(int fd, char** buffer, char* tmp)
{
    int nbytes;
    char* nl;
    char* nstr;

    nbytes = 0;
    nstr = NULL;

    nl = ft_strchr(*buffer, '\n');
    while (nl == NULL)
    {
        nbytes = read(fd, tmp, BUFFER_SIZE);
        if (nbytes <= 0)
        {
            return join_line(nbytes, buffer);
        }
        tmp[nbytes] = 0;
 
        nstr = ft_strjoin(*buffer, tmp);
        free(*buffer);
        *buffer = nstr;
        nl = ft_strchr(*buffer, '\n');
    }
    return join_line(nl - *buffer + 1, buffer);
}

char *get_next_line(int fd)
{
    char *tmp;
    char *res;
    static char *buffer;

    if (fd < 0 || BUFFER_SIZE <= 0)
    {
        return NULL;
    }

    tmp = malloc((BUFFER_SIZE + 1)*sizeof(char));
    
    if(tmp == NULL)
    {
        return NULL;
    }

    if(!buffer)
    {
        buffer = ft_strdup("");
    }

    res = read_line(fd, &buffer, tmp);
    free(tmp);

    return res;
}