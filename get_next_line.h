/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfischer <cfischer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:58:34 by cfischer          #+#    #+#             */
/*   Updated: 2022/04/13 21:41:22 by cfischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

#include <unistd.h>
#include <stdlib.h>

/**
 * @brief Write a function that returns
 *  a line read from a file descriptor.
 * @param fd The file descriptor to read from
 * @return Read line or 
 * Null there is nothing else to read, or an error
 * occurred.
 */
char *get_next_line(int fd);

/**
 * @brief Returns a pointer to the
 * first occurrence of the character c in the string s.
 *
 * @param s Pointer to the string memory area
 * @param c Character to be searched inside the string s
 * @return char* Return a pointer to the matched character
 * or NULL if the character is not found.
 */
char		*ft_strchr(const char *s, int c);

/**
 * @brief calculates the length of the string
 * pointed to by str, excluding the terminating null byte ('\0').
 *
 * @param str	Pointer to the initial area of the string
 * @return		size_t Returns the number of bytes in the
 * string pointed to by str.
 */
size_t		ft_strlen(const char *str);

/**
 * @brief Allocates (with malloc(3)) and returns a substringfrom the string ’s’.
 * The substring begins at index ’start’ and is ofmaximum size ’len’.
 *
 * @param s		The string from which to create the substring.
 * @param start	The start index of the substring in the string’s’.
 * @param len	The maximum length of the substring.
 * @return char* Returns the substring. NULL if the allocation fails.
 */
char		*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief Allocates (with malloc(3)) and returns a newstring,
 * which is the result of the concatenationof ’s1’ and ’s2’.
 *
 * @param s1 The prefix string
 * @param s2 The suffix string
 * @return char* Returns the new string or NULL if the allocation fails.
 */
char		*ft_strjoin(char const *s1, char const *s2);

#endif