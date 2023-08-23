/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaludov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:33:22 by zzaludov          #+#    #+#             */
/*   Updated: 2023/03/07 20:43:43 by zzaludov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;

	i = 0;
	dup = (char *) malloc (ft_strlen(s) + 1);
	if (!dup)
		return (NULL);
	while (i < (int)ft_strlen(s))
	{
		dup[i] = s[i];
		i++;
	}
	dup [i] = '\0';
	return (dup);
}

/*int main()
{
	char s1[] = "lorem ipsum dolor sit amet";
	char* s2 = ft_strdup(s1);
	printf ("%s", s2);
	return 0;
}*/
