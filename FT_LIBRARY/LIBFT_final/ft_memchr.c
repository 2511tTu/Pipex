/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaludov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:41:31 by zzaludov          #+#    #+#             */
/*   Updated: 2023/03/01 22:08:09 by zzaludov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char		*m;
	size_t		i;

	i = 0;
	m = (char *) s;
	if (c > 256)
		c = c % 256;
	while (i < n)
	{
		if (m[i] == c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}
