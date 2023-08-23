/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaludov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 23:06:39 by zzaludov          #+#    #+#             */
/*   Updated: 2023/04/10 22:06:14 by zzaludov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 

char	*trim_source(char *source)
{
	char	*trim;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (source[i] != '\n' && source[i])
		i++;
	if (!source[i])
	{
		free(source);
		return (NULL);
	}
	trim = (char *) malloc (gnl_strlen(source) - i + 1);
	if (!trim)
		return (NULL);
	i++;
	while (source[i])
		trim[j++] = source[i++];
	trim[j] = '\0';
	free(source);
	return (trim);
}

char	*create_line(char *source)
{
	int		i;
	char	*line;

	i = 0;
	if (!*source)
		return (NULL);
	while (source[i] != '\n' && source[i])
		i++;
	line = (char *) malloc (i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (source[i] != '\n' && source[i])
	{
		line[i] = source[i];
		i++;
	}
	line[i] = source[i];
	line[++i] = '\0';
	return (line);
}

char	*read_source(int fd, char *source)
{
	int		buff_size;
	char	*buffer;

	buff_size = 1;
	buffer = (char *) malloc (BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (buff_size > 0 && !find_next_line(source))
	{
		buff_size = read(fd, buffer, BUFFER_SIZE);
		if (buff_size == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[buff_size] = '\0';
		source = re_source(source, buffer);
	}
	free(buffer);
	return (source);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*source;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	source = read_source(fd, source);
	if (!source)
		return (NULL);
	line = create_line(source);
	source = trim_source(source);
	return (line);
}
/*
int main()
{
	int	fd;
	char	*line;
	int	i = 0;
	
	fd = open("try.txt", 0);
	line = "";
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("+++%s", line);
		i++;
	}
	char	*a = (get_next_line(fd));
	printf ("%s", a);
	free (a);
	char    *b = (get_next_line(fd));
	printf ("b = %s", b);
	free (b);
	close(fd);
	return 0;
}*/
