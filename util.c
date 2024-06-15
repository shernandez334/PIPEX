/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahernan <sahernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:11:06 by sahernan          #+#    #+#             */
/*   Updated: 2024/06/15 18:33:57 by sahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipe_error(int error)
{
	if (error == ERROR_ARGS)
		return (write(2, "Too few arguments\n", 18), 1);
	else if (error == ERROR_PIPE)
		return (perror(""), 141);
	else if (error == ERROR_INFILE)
		return (perror(""), 0);
	else if (error == ERROR_OUTFILE)
		return (perror(""), 1);
	else if (error == ERROR_COMMAND)
		return (perror(""), 127);
	else
		return (1);
}

char *env_path(char **env, char *args)
{
	int i;
	char *path;
	char *current_path;
	char **env_path;
	char **command_path;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	path = env[i];
	env_path = ft_split(path + 5, ':');
	command_path = ft_split(args, ' ');
	i = 0;
	while (env_path[i])
	{
		current_path = ft_strjoin(env_path[i], "/");
		current_path = ft_strjoin(current_path, command_path[0]);
		if (!access(current_path, X_OK | F_OK))
			return (current_path);
		i++;
	}
	exit(pipe_error(ERROR_COMMAND));
}

void	check_files(t_pipx *pipx, char **args)
{
	if (pipx->id == 1)
	{
		if (pipx->i == pipx->ac - 2)
			pipx->outfile_fd = open(args[pipx->ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	}
	else
	{	
		//fprintf(stderr, "i: %i\n", pipx->i);
		if (pipx->i == pipx->ac - 2)
		{
			pipx->outfile_fd = open(args[pipx->ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
			//fprintf(stderr, "i: %i\n", pipx->i);
			//fprintf(stderr, "id: %i\n", pipx->id);	
		}
		else if (pipx->i == 2)
			pipx->infile_fd = open(args[pipx->i - 1], O_RDONLY);
	}
}

void exec_pipes(t_pipx *pipx, char **env, char **args)
{
	pipx->env_path = env_path(env, args[pipx->i]);
	pipx->cmnd = ft_split(args[pipx->i], ' ');
	if (pipx->id == 1 && pipx->i == 3)
		here_doc(pipx, args[2]);
	else
		close_pipes(pipx);
	if (execve(pipx->env_path, pipx->cmnd, env) < 0)
		exit(pipe_error(ERROR_COMMAND));
}

void	close_pipes(t_pipx *pipx)
{	
	if (pipx->i == 2)
	{   
		dup2(pipx->infile_fd, STDIN_FILENO);
		fprintf(stderr, "INFILE FD: %i\n", pipx->infile_fd);
		close(pipx->infile_fd);
		dup2(pipx->pipe_fd[1], STDOUT_FILENO);
		close(pipx->pipe_fd[0]);	
	} 
	else if (pipx->i == pipx->ac - 2)
	{
		dup2(pipx->outfile_fd, STDOUT_FILENO);
		fprintf(stderr, "OUTFILE FD: %i\n", pipx->outfile_fd);
		close(pipx->outfile_fd);
		dup2(pipx->pipe_fd[0], STDIN_FILENO);
		close(pipx->pipe_fd[1]);	
	}
}
