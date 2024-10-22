/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:21:53 by sahernan          #+#    #+#             */
/*   Updated: 2024/07/01 16:54:35 by sahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void pipe_init(t_pipx *pipx, char **args, char **env)
{
	pid_t pid;
	
	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == 0)
	{
		if ((pipx->id == 0 && pipx->i == 2) || (pipx->i == pipx->ac -2))
		{
			check_files(pipx, args);
			if (pipx->infile_fd == -1 || pipx->outfile_fd == -1)
			{
				pipx->pipe_count -= 1;
				if (pipx->i == pipx->ac -2)
					exit(pipe_error(ERROR_OUTFILE));
				exit(pipe_error(ERROR_INFILE));
			}
		}
		exec_pipes(pipx, env, args);
	}
	close(pipx->pipe_fd[1]);
}

void    check_files(t_pipx *pipx, char **args)
{
     if (pipx->id == 1 && pipx->i == pipx->ac -2)
         pipx->outfile_fd = open(args[pipx->ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
     else if (pipx->i == pipx->ac - 2 || (pipx->id == 0 && pipx->i == 2))
     {
		if (pipx->i == pipx->ac - 2)
		{ 
			pipx->outfile_fd = open(args[pipx->ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		}   
         else if (pipx->i == 2)
             pipx->infile_fd = open(args[pipx->i - 1], O_RDONLY);
     }
}

void exec_pipes(t_pipx *pipx, char **env, char **args)
{

	pipx->env_path = env_path(env, args[pipx->i]);
	if (pipx->env_path == NULL)
	{
		if (pipx->i == pipx->ac - 2)
			exit(pipe_error(ERROR_COMMAND));
		else
			exit(pipe_error(ERROR_INFILE));
	}
	pipx->cmnd = ft_split(args[pipx->i], ' ');
	if (pipx->id == 1 && pipx->i == 3)
		here_doc(pipx, args[2]); 
	else
		dup_pipes(pipx);
	if (execve(pipx->env_path, pipx->cmnd, env) < 0)
		exit(pipe_error(ERROR_COMMAND));
}

char    *env_path(char **env, char *args)
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
		current_path = ft_strjoin_ppx(current_path, command_path[0]);
		if (access(current_path, X_OK) ==  0)
        { 
			i = 0;
			while (env_path[i])
			{
				free(env_path[i]);
				i++;
			}
			i = 0;
			while(command_path[i])
			{
				free(command_path[i]);
				i++;
			}
			if (env_path)
			{
				 free(env_path);
				env_path = NULL;
			}
			//free(env_path);
			free(command_path);
			return (current_path);
		}
		free(current_path);
		i++;
	}
	while (i > 0)
	{
		free(env_path[i]);
		free(command_path[i]);
		i--;
	}
	free(env_path);
	return (NULL);
}

void    here_doc(t_pipx *pipx, char *limiter)
{   
	char *line;
     
	line = get_next_line(0);
	while(ft_strcmp_ppx(line, limiter) != 0)
	{
		//printf("pene\n");   
		write(pipx->pipe_fd[1], line, ft_strlen(line));
		free(line);
		line = get_next_line(0);
	}
	free(line);
	//printf("fd: ", pipx->pipe_fd[0]);
	//printf("fd: ", pipx->pipe_fd[1]);
	close(pipx->pipe_fd[1]);
	dup2(pipx->pipe_fd[0], STDIN_FILENO);
	close(pipx->pipe_fd[0]);
	close(3);
	close(4); 
	exit(0);
}
