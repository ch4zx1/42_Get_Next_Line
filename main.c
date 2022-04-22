/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfischer <cfischer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 21:56:21 by cfischer          #+#    #+#             */
/*   Updated: 2022/04/13 21:56:28 by cfischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
    char* teste;
    int fd;
    fd = open("teste", O_RDONLY);
    teste = get_next_line(fd);

    printf("%s", teste);

    teste = get_next_line(fd);

    printf("%s", teste);

    teste = get_next_line(fd);

    printf("%s", teste);

    
    return 0;
}
