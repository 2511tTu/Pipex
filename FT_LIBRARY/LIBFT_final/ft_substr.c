/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaludov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:53:46 by zzaludov          #+#    #+#             */
/*   Updated: 2023/03/07 20:49:26 by zzaludov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
//#include <stdio.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*sub;
	size_t		i;

	i = 0;
	if (!s)
		return (NULL);
	if (start + (int)len <= ft_strlen(s))
		sub = (char *) malloc (len + 1);
	else if (start > ft_strlen(s))
		sub = (char *) malloc (1);
	else
		sub = (char *) malloc (ft_strlen(s) - start + 1);
	if (!sub)
		return (NULL);
	while (i < len && start + (int)i < ft_strlen(s) && s[i + start])
	{
		sub[(int)i] = s[(int)i + start];
		i++;
	}
	sub [(int)i] = '\0';
	return (sub);
}

/*int main()
{
	char ww[] = "Upsee...";
	char *wq = ft_substr(ww, 10, 10);
	printf ("%s", wq);
	return 0;
}*/
