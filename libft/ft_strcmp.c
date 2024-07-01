/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 21:32:17 by sahernan          #+#    #+#             */
/*   Updated: 2024/06/28 17:00:15 by sahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strcmp_ppx(char *line, char *limiter)
{
	int i; 

	if (!line || !limiter)
		return (0);
	i = 0;
	while (line[i])
	{
		if (line[i] == '\n' && !limiter[i])
			return (0);
		else if (!limiter[i])
			return (1);
		i++;
	}
	return (1);
}
