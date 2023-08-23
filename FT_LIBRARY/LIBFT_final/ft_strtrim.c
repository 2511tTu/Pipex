/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaludov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:35:03 by zzaludov          #+#    #+#             */
/*   Updated: 2023/03/07 20:48:06 by zzaludov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		i;
	int		j;
	int		v;

	i = 0;
	j = ft_strlen (s1) - 1;
	while (ft_strchr(set, s1[i]) && (j >= i))
		i++;
	while (ft_strchr(set, s1[j]) && (j >= i))
		j--;
	trim = (char *) malloc (j - i + 2);
	if (!trim)
		return (NULL);
	v = 0;
	while (i <= j)
	{
		trim[v] = s1[i];
		i++;
		v++;
	}
	trim[v] = '\0';
	return (trim);
}
