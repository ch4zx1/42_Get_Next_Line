/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfischer <cfischer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 18:40:44 by cfischer          #+#    #+#             */
/*   Updated: 2022/04/23 19:18:18 by cfischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <stdlib.h>

char		*get_next_line(int fd);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlen(const char *str);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s1);

#endif