/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:22:02 by brheaume          #+#    #+#             */
/*   Updated: 2022/12/15 09:12:03 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_isreturnline(const char *src)
{
	int	i;

	i = 0;
	while (src[i])
		if (src[i++] == '\n')
			return (1);
	return (0);
}

int	ft_atin(const char *src, const char c)
{
	int	i;

	i = 0;
	if (src)
		while (src[i] != c && src[i])
			i++;
	return (i);
}

char	*ft_substr(char *src, size_t *len)
{
	size_t	i;
	char	*res;

	i = 0;
	while (i < *len && src[i])
		i++;
	*len = i;
	res = ft_calloc(sizeof(char), (*len + 1));
	if (!res)
		return (0);
	i = 0;
	while (i < *len)
	{
		res[i] = src[i];
		i++;
	}
	return (res);
}

char	*ft_read(char *res, char *current, int *rv, const int fd)
{
	while (!ft_isreturnline(res))
	{
		ft_bzero(current, BUFFER_SIZE + 1);
		*rv = read(fd, current, BUFFER_SIZE);
		if (*rv <= 0)
			break ;
		res = ft_strjoin(res, current);
	}
	current = ft_xfree(current);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*store;
	char		*tmp2;
	char		*tmp;
	size_t		rm;
	int			rv;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (store = ft_xfree(store));
	if (!store)
		store = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	store = ft_read(store, tmp, &rv, fd);
	if (rv == -1 || (!rv && !store[0]))
	{
		store = ft_xfree(store);
		return (store);
	}
	rm = ft_atin(store, '\n') + 1;
	tmp = ft_substr(store, &rm);
	tmp2 = store;
	store = ft_strjoin(NULL, store + rm);
	ft_xfree(tmp2);
	return (tmp);
}
