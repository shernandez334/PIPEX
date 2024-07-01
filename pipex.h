/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahernan <sahernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:13:55 by sahernan          #+#    #+#             */
/*   Updated: 2024/07/01 15:47:46 by sahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define ERROR_ARGS             0 // Error en numero de argumentos
# define ERROR_PIPE				1 // Error Pipe
# define ERROR_INFILE			2 // Error estandar Imfile
# define ERROR_OUTFILE			3 // Error estandar Outfile
# define ERROR_COMMAND			4 // Error econcontrando comando

#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"
#include <fcntl.h>

typedef struct {
	int		ac;
	int		i;
	int		id;
	int 	infile_fd;
	int 	outfile_fd;
	int		pipe_count;
	int		old_pipefd[2];
	int		pipe_fd[2];
	char	*env_path;
	char	**cmnd;
}t_pipx;

int     pipe_counter(t_pipx *pipx);
int     pipe_error(int error);
void	execute_pipeline(t_pipx *pipx, char **args, char **env);
void	pipe_init(t_pipx *pipx, char **args, char **env);
void	check_files(t_pipx *pipx, char **args);
char	*env_path(char **env, char *args);
void	exec_pipes(t_pipx *pipx, char **env, char **args);
void    here_doc(t_pipx *pipx, char *limiter);
void    dup_pipes(t_pipx *pipx);
int		pipe_creator(t_pipx *pipx);
void    close_pipes(t_pipx *pipx, int close_id);

#endif
