/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahernan <sahernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:37:15 by sahernan          #+#    #+#             */
/*   Updated: 2024/06/15 18:17:36 by sahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	if (!ft_strncmp(args[1], "here\\_doc", 9))
	{
        pipx.id = 1;
        pipx.i += 1;
	}
	execute_pipeline(&pipx, args, env);
	return (0);
}
