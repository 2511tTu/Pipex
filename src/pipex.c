/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaludov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 21:30:40 by zzaludov          #+#    #+#             */
/*   Updated: 2023/08/10 21:30:51 by zzaludov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_message(t_pipex p, char *str)
{
	perror(str);
	free_array(p.envp);
	free_array(p.argv);
	exit(EXIT_FAILURE);
}

void	child(t_pipex p, int pos)
{
	char	**cmds;
	int		end[2];
	pid_t	pid;

	if (pipe(end) == -1)
		error_message(p, "Error ");
	pid = fork();
	if (pid == -1)
		error_message(p, "Error ");
	else if (pid == 0)
	{
		close(end[0]);
		dup2(end[1], STDOUT_FILENO);
		close(end[1]);
		cmds = ft_split(p.argv[pos + 2 + p.heredoc], ' '); 
		path_finder(cmds, p.envp);
	}
	else
	{
		close(end[1]);
		dup2(end[0], STDIN_FILENO);
		close(end[0]);
		waitpid(pid, NULL, 0);
	}
}

void	parent(t_pipex p)
{
	char	**cmds;

	if (p.heredoc == 0)
		p.outfile = open(p.argv[p.argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	else
		p.outfile = open(p.argv[p.argc - 1], O_CREAT | O_RDWR | O_APPEND, 0644);
	if (p.outfile < 0)
		error_message(p, "Error ");
	dup2(p.outfile, STDOUT_FILENO);
	close(p.outfile);
	cmds = ft_split(p.argv[p.argc - 2], ' ');
	path_finder(cmds, p.envp);
}

void	pipelines(t_pipex p)
{
	int		i;

	i = 0;
	if (p.heredoc == 1)
		here_doc(p);
	else
	{
		p.infile = open(p.argv[1], O_RDONLY);
		if (p.infile < 0)
			error_message(p, "Error ");
		dup2(p.infile, STDIN_FILENO);
		close(p.infile);
	}
	while (i < p.n_cmd - 1)
	{
		child(p, i);
		i++;
	}
	parent(p);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	p;

	if (argc < 5)
	{
		ft_printf("Too few arguments\n");
		exit(EXIT_FAILURE);
	}
	p.heredoc = 0;
	p.argc = argc;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		p.heredoc = 1;
	if (argc < 6 && p.heredoc == 1)
	{
		ft_printf("Too few arguments\n");
		exit(EXIT_FAILURE);
	}
	p.envp = to_struct(envp);
	p.argv = to_struct(argv);
	p.n_cmd = argc - 3 - p.heredoc;
	pipelines(p);
	free_array(p.envp);
	free_array(p.argv);
	return (0);
}
