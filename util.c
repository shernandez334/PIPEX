/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahernan <sahernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:11:06 by sahernan          #+#    #+#             */
/*   Updated: 2024/06/26 19:37:26 by sahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int pipe_error(int error)
{
      if (error == ERROR_ARGS)
          return (write(2, "Too few arguments\n", 18), 1);
      else if (error == ERROR_PIPE)
          return (perror(""), -1);
      else if (error == ERROR_INFILE)
          return (perror(""), 0);
      else if (error == ERROR_OUTFILE)
          return (perror(""), 1);
      else if (error == ERROR_COMMAND)
          return (perror(""), 127);
      else
         return (1);
}

void	dup_pipes(t_pipx *pipx)
{
	if (pipx-> id == 0 && pipx->i == 2)
	{
		dup2(pipx->infile_fd, STDIN_FILENO);
		dup2(pipx->pipe_fd[1], STDOUT_FILENO);
		close_pipes(pipx, 0);
	}
	else if (pipx->i == pipx->ac - 2)
	{
		dup2(pipx->outfile_fd, STDOUT_FILENO);
		dup2(pipx->pipe_fd[0], STDIN_FILENO);
		close_pipes(pipx, 1);
	}
	else
	{
		dup2(pipx->old_pipefd[0], STDIN_FILENO);
		dup2(pipx->pipe_fd[1], STDOUT_FILENO);
		close_pipes(pipx, 2);
	}
}

void	close_pipes(t_pipx *pipx, int close_id)
{
	if (close_id == 0)
	{	
		close(pipx->infile_fd);
		close(pipx->pipe_fd[0]);
		close(pipx->pipe_fd[1]);
	}
	else if (close_id == 1)
	{
		close(pipx->outfile_fd);
		close(pipx->pipe_fd[0]);
		close(pipx->pipe_fd[1]);
		close(pipx->old_pipefd[0]);
		close(pipx->old_pipefd[1]);
	}
	else if (close_id == 2)
	{
		close(pipx->old_pipefd[0]);	
		close(pipx->old_pipefd[1]);
		close(pipx->pipe_fd[1]);
		close(pipx->pipe_fd[0]);
	}
}
