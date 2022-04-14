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


char *get_next_line(int fd)
{
    int nbytes;
    char *tmp;
    char *s;

    s = malloc((BUFFER_SIZE + 1)*sizeof(char));
    nbytes = read(fd, s, BUFFER_SIZE);
    tmp = ft_strchr(s, '\n');
    while (tmp == NULL)
    {
        nbytes = read(fd, s, BUFFER_SIZE);
    }

    printf ("%s\n", s);
    printf ("%d\n", nbytes);
    return s;
}