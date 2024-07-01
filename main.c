/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahernan <sahernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:37:15 by sahernan          #+#    #+#             */
/*   Updated: 2024/06/28 16:52:07 by sahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    execute_pipeline(t_pipx *pipx, char **args, char **env);
int		pipe_counter(t_pipx *pipx);
int		pipe_creator(t_pipx *pipx);

int main(int ac, char **args, char **env)
{
	t_pipx pipx;
	
	if (ac < 5)
		exit(pipe_error(ERROR_ARGS));
	pipx.ac = ac;	
	pipx.i = 2;
	pipx.id = 0;
	pipx.infile_fd = 0;
	pipx.outfile_fd = 0;
	pipx.env_path = NULL;
	if (!ft_strncmp(args[1], "here_doc", 9))
	{
		pipx.id = 1;
		pipx.i += 1;
	}
	execute_pipeline(&pipx, args, env);
	close(3);
	close(4);
	close(5);
	close(6);
	return (0);
}

void    execute_pipeline(t_pipx *pipx, char **args, char **env)
{	
	
	pipx->pipe_count = pipe_counter(pipx);
	while (pipx->pipe_count >= 0)
	{
		pipx->old_pipefd[0] = pipx->pipe_fd[0];
		pipx->old_pipefd[1] = pipx->pipe_fd[1];
		if (pipe_creator(pipx) < 0)
			exit(pipe_error(ERROR_PIPE));
		pipe_init(pipx, args, env);
		pipx->i += 1;
		wait(NULL);
	}
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
 
int pipe_creator(t_pipx *pipx)
{
	if (pipx->pipe_count >= 1 && pipx->i <= pipx->ac - 3)
	{
		pipx->pipe_count -= 1;
		if(pipe(pipx->pipe_fd) < 0)
			return(-1);
		if ((pipx->id == 0 && pipx->i > 2) || (pipx->id == 1 && pipx->i > 3))
		{	
			if(pipe(pipx->pipe_fd) < 0)
				return(-1); 
		}
	}
     else if (pipx->pipe_count == 0)
         pipx->pipe_count -= 1;
     return (0);
}
