/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaludov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 21:31:02 by zzaludov          #+#    #+#             */
/*   Updated: 2023/08/10 21:31:05 by zzaludov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (array == NULL)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	**to_struct(char **src)
{
	int		i;
	char	**dest;

	i = 0;
	dest = NULL;
	while (src[i] != NULL)
		i++;
	dest = ft_calloc(i + 1, sizeof(char **));
	i = 0;
	while (src[i] != NULL)
	{
		dest[i] = ft_strdup(src[i]);
		i++;
	}
	return (dest);
}

void	find_delimiter(t_pipex p, int *end)
{
	int		i;
	char	*line;

	i = 0;
	while (i++ < p.n_cmd - 1)
		write(STDOUT_FILENO, "pipe ", 5);
	write(STDOUT_FILENO, "heredoc> ", 9);
	line = get_next_line(0);
	if (ft_strncmp(line, p.argv[2], ft_strlen(p.argv[2])) == 0)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}
	write(end[1], line, ft_strlen(line));
	free(line);
}

void	here_doc(t_pipex p)
{
	int		end[2];
	pid_t	pid;

	if (pipe(end) == -1)
		error_message(p, "Error ");
	pid = fork();
	if (pid == -1)
		error_message(p, "Error ");
	if (pid == 0)
	{
		while (1)
			find_delimiter(p, end);
	}
	else
	{
		close(end[1]);
		dup2(end[0], STDIN_FILENO);
		wait(NULL);
	}
}

void	path_finder(char **cmds, char **envp)
{
	char	**paths;
	char	*path;
	char	*path_part;
	int		i;

	i = 0;
	while (ft_strncmp(envp[i], "PATH", 4) != 0) 
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		path_part = ft_strjoin(paths[i], "/");
		path = ft_strjoin(path_part, cmds[0]);
		free(path_part);
		if (access(path, X_OK) == 0)
		{
			execve(path, cmds, envp);
			perror("execve");
		}
		free(path);
		i++;
	}
	free_array(paths);
	free_array(cmds);
}
