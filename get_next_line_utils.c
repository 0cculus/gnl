/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:49:09 by brheaume          #+#    #+#             */
/*   Updated: 2022/12/15 09:08:00 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_xfree(char *src)
{
	if (src)
		free(src);
	return (NULL);
}

void	ft_bzero(void *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		((char *)src)[i++] = 0;
}

void	*ft_calloc(unsigned int size, unsigned int count)
{
	void	*res;

	res = malloc(size * count);
	if (res)
	{
		ft_bzero(res, size * count);
		return (res);
	}
	return (0);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*res;

	res = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!res)
		return (res = ft_xfree(res));
	i = 0;
	j = 0;
	while (s1 && s1[i])
		res[j++] = s1[i++];
	i = 0;
	while (s2 && s2[i])
		res[j++] = s2[i++];
	ft_xfree(s1);
	if (*res == 0)
		res = ft_xfree(res);
	return (res);
}

size_t	ft_strlen(const char *src)
{
	size_t	i;

	i = 0;
	while (src && src[i])
		i++;
	return (i);
}
