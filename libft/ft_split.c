/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 21:48:47 by ewatanab          #+#    #+#             */
/*   Updated: 2020/07/17 11:39:51 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**alloc_container(int i)
{
	char	**container;

	container = malloc((i + 1) * sizeof(char *));
	if (!container)
		return (NULL);
	container[i] = NULL;
	return (container);
}

static char	**rec(char const *s, char c, int i)
{
	char const	*ptr;
	char		**container;

	while (*s == c)
		s++;
	if (!*s)
		return (alloc_container(i));
	ptr = s;
	while (*s && *s != c)
		s++;
	ptr = ft_substr(ptr, 0, s - ptr);
	if (!ptr)
		return (NULL);
	container = rec(s, c, i + 1);
	if (!container)
	{
		free((void *)ptr);
		return (NULL);
	}
	container[i] = (char *)ptr;
	return (container);
}

char	**ft_split(char const *s, char c)
{
	if (!s)
		return (NULL);
	return (rec(s, c, 0));
}
