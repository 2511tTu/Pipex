/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaludov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:42:13 by zzaludov          #+#    #+#             */
/*   Updated: 2023/03/01 16:47:36 by zzaludov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//size_t	ft_strlen(const char *s);

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	i;

	i = 0;
	if (size == 0 && !dst)
		return (0);
	dst_len = ft_strlen(dst);
	if (size < dst_len)
		return (size + ft_strlen(src));
	while (i + dst_len + 1 < size && src[i])
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (ft_strlen(src) + dst_len);
}
/*
int main()
{
	char a[30] = "1";
	size_t i = ft_strlcat(a, "126", 3);
	printf ("%s, %zu", a, i);
	return (0);
}*/
