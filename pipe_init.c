/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:21:53 by sahernan          #+#    #+#             */
/*   Updated: 2024/06/15 18:34:10 by sahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_pipeline(t_pipx *pipx, char **args, char **env)
{
	//int status;
	
	pipx->pipe_count = pipe_counter(pipx);
	printf("pipe count: %i\n", pipx->pipe_count);
	while (pipx->pipe_count >= 0)
	{
		if (pipe(pipx->pipe_fd) < 0)
			exit(pipe_error(ERROR_PIPE));
		pipe_init(pipx, args, env);
		wait(NULL);
	}
	/*while ()
	{	
		if (pid == waitpid(pid, &status, 0))
			exit(0);
	}*/
}

int pipe_counter(t_pipx *pipx)
{
	int pipe_count;

	pipe_count = 0;
	if (pipx->id == 1)
		pipe_count = pipx->ac - 5;
	else
		pipe_count = pipx->ac - 4;
	return (pipe_count);
}

void pipe_init(t_pipx *pipx, char **args, char **env)
{
	pid_t pid;
	
	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == 0)
	{
		check_files(pipx, args);
		if (pipx->infile_fd == -1 || pipx->outfile_fd == -1)
		{
			if (pipx->i == pipx->ac - 2)
				exit(pipe_error(ERROR_OUTFILE));
			exit(pipe_error(ERROR_INFILE));
		}
		exec_pipes(pipx, env, args);
	}
	if (pipx->i != 2 && pipx->i != pipx->ac - 2)
	{
		dup2(pipx->pipe_fd[0], STDIN_FILENO);
	}
	pipx->i += 1;
	pipx->pipe_count -= 1;	
}

void	here_doc(t_pipx *pipx, char *args)
{
	char *line;

	line = get_next_line(0); 
	while(strncmp(line, args, ft_strlen(args)) != 0)
	{
		write(pipx->pipe_fd[1], line, ft_strlen(line));
		line = get_next_line(0);	
	}
	dup2(pipx->pipe_fd[1], STDOUT_FILENO);
	close(pipx->pipe_fd[1]);
}

