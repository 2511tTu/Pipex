/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaludov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:30:23 by zzaludov          #+#    #+#             */
/*   Updated: 2023/07/25 21:30:26 by zzaludov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include "../FT_LIBRARY/ft_library.h"

typedef struct s_pipex
{
	int		argc;
	char	**argv;
	char	**envp;
	int		infile;
	int		outfile;
	int		n_cmd;
	int		heredoc;
}	t_pipex;

char	**to_struct(char **src);
void	error_message(t_pipex p, char *str);
void	free_array(char **array);
void	here_doc(t_pipex p);
void	path_finder(char **cmds, char **envp);

#endif
