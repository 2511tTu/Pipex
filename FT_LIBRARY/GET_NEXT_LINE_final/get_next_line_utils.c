/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaludov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 23:24:55 by zzaludov          #+#    #+#             */
/*   Updated: 2023/04/10 20:51:33 by zzaludov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*find_next_line(char *text)
{
	int	i;

	i = 0;
	if (!text)
		return (NULL);
	while (text[i])
	{
		if (text[i] == '\n')
			return ((char *)text + i);
		else
			i++;
	}
	return (NULL);
}

int	gnl_strlen(char	*str)
{
	int	size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

char	*re_source(char *origin, char *add)
{
	char	*temp;
	int		i;
	int		j;

	if (!origin)
	{
		origin = (char *) malloc (1);
		*origin = '\0';
	}
	temp = (char *) malloc (gnl_strlen(origin) + gnl_strlen(add) + 1);
	if (!temp)
		return (NULL);
	i = -1;
	j = 0;
	while (origin[++i])
		temp[i] = origin[i];
	while (add[j])
		temp[i++] = add[j++];
	temp[i] = '\0';
	free(origin);
	return (temp);
}
