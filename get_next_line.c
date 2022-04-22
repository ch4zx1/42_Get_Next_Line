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

    if (nlp <= 0)
    {
        if(**buffer == 0)
        {
            free(*buffer);
            *buffer = NULL;
            return NULL;
        }

        res = *buffer;
        *buffer = NULL;
        return res;
    }
    tmp = ft_substr(*buffer, nlp, BUFFER_SIZE);
    res = *buffer; 
    res[nlp] = 0;
    *buffer = tmp;
    return res;
}

char *read_line(int fd, char** buffer, char* tmp)
{
    int nbytes; //n de bytes
    char* nl; //new line
    char* nstr; //new str

    nbytes = 0;
    nstr = NULL;

    //procura 0 barra \n dentro de buffer
    nl = ft_strchr(*buffer, '\n');

    //check se nl = a null
    while (nl == NULL)
    {
        //le o fd e passa o valor para tmp
        //retorna o numero de bytes
        nbytes = read(fd, tmp, BUFFER_SIZE);
        
        //se nbytes for menor ou igual a zero
        if (nbytes <= 0)
        {
            return join_line(nbytes, buffer);
        }

        //coloca um zero no final da string pra nao dar leak na memoria
        tmp[nbytes] = 0; 

        //concatenar o valor de buffer com tmp
        nstr = ft_strjoin(*buffer, tmp);
        //dar free no buffer
        free(*buffer);
        //ele vai passar o valor de nstr pra buffer
        *buffer = nstr;
        //check se a novo buffer tem barra n, 
        //se nao tiver, retorna null e continua 
        nl = ft_strchr(*buffer, '\n');
    }
    return join_line(nl - *buffer + 1, buffer);
    //
    //vai subtrair nl, que eh a frase ate o \n
    //do *buffer que eh o endereco do primeiro caracter
}

char *get_next_line(int fd)
{
    char *tmp;
    char *res; //resultado
    static char *buffer[256]; //

    //Check: se fd for menor que 0 ou buffer_size é menor ou igual
    //a 0, retorna NULL
    if (fd < 0 || BUFFER_SIZE <= 0)
    {
        return NULL;
    }

    //aloca o tmp com buffer_size + 1 (+1 para o /0)
    tmp = malloc((BUFFER_SIZE + 1)*sizeof(char));
    
    //caso o malloc nao de certo, retorna null
    if(tmp == NULL)
    {
        return NULL;
    }

    if(!buffer[fd]) //checa se o buffer ta vazio
    {
        buffer[fd] = ft_strdup("");
        //inicia com strdup, que vai conter toda a frase 
    }

    //passa argumentos para ler a linha
    res = read_line(fd, &buffer[fd], tmp);

    //limpa o tmp para ler o proximo conteudo no buffer
    free(tmp);

    //retorna resultado
    return res;
}