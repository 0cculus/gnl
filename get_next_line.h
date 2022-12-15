/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:19:03 by brheaume          #+#    #+#             */
/*   Updated: 2022/12/13 13:08:36 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

void	*ft_xfree(char *src);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *src);
int		ft_isreturnline(const char *c);
void	ft_bzero(void *src, size_t len);
char	*ft_substr(char *src, size_t *len);
char	*ft_strjoin(char *s1, const char *s2);
int		ft_atin(const char *src, const char c);
void	*ft_calloc(unsigned int size, unsigned int count);
char	*ft_read(char *res, char *current, int *rv, const int fd);

#endif
