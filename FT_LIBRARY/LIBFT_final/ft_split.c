/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaludov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:00:30 by zzaludov          #+#    #+#             */
/*   Updated: 2023/03/07 21:00:45 by zzaludov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <stdlib.h>

static int	string_count(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && i == 0 && s[i])
			j++;
		if (s[i] == c && s[i] && s[i + 1] != c && s[i + 1] != '\0')
			j++;
		i++;
	}
	return (j);
}

static int	c_position(char const *s, char c, int i)
{
	int	j;

	j = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i])
	{
		j++;
		i++;
	}
	return (j);
}

static char	**splitting(char **array, char const *s, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	array[j] = (char *) malloc (c_position(s, c, i) + 1);
	k = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0' && k != 0)
		{
			array[j++][k] = '\0';
			i++;
			array[j] = (char *) malloc (c_position(s, c, i) + 1);
			k = 0;
		}
		else if (s[i] != c)
			array[j][k++] = s[i++];
		else
			i++;
	}
	array[j][k] = '\0';
	array[j + 1] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char		**array;

	if (!s)
		return (NULL);
	array = (char **) malloc (sizeof(char *)
			* (string_count(s, c) + 1));
	if (!array)
		return (NULL);
	if (!string_count(s, c))
	{
		array[0] = NULL;
		return (array);
	}
	return (splitting(array, s, c));
}
/*
int main()
{
//	char word[] = "Here-I-am-!";
	char	**array;
	array = ft_split("  tripouille  42  ", ' ');
	int i = 0;

	while (i < 2)
	{ 
		printf("%s-\n", array[i]);
		i++;
	}
	return 0;
}*/
