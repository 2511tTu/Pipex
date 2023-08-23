/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaludov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:20:15 by zzaludov          #+#    #+#             */
/*   Updated: 2023/02/16 22:23:29 by zzaludov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*temp;
	int		i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	temp = (char *)src;
	if (dest < src)
	{
		while (i < (int)n)
		{
			*(char *)(dest + i) = temp[i];
			i++;
		}
	}
	else
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			*(char *)(dest + i) = temp[i];
			i--;
		}
	}
	return (dest);
}
