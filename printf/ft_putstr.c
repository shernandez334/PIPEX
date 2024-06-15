/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahernan <sahernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:20:54 by sahernan          #+#    #+#             */
/*   Updated: 2024/02/09 12:34:57 by sahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
	{
		if (write(1, "(null)", 6) != 6)
			return (-1);
		return (6);
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_putchr(str[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}
