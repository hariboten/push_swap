/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 18:55:46 by ewatanab          #+#    #+#             */
/*   Updated: 2020/06/22 19:03:24 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*buf;

	buf = malloc(num * size);
	if (!buf)
		return (NULL);
	ft_bzero(buf, num * size);
	return (buf);
}
