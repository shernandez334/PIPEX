/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahernan <sahernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:25:59 by sahernan          #+#    #+#             */
/*   Updated: 2024/06/11 18:08:50 by sahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbrs(unsigned int n, int *i)
{
	if (n > 9)
	{
		if (ft_putnbrs(n / 10, i) == -1)
			return (-1);
		if (ft_putnbrs(n % 10, i) == -1)
			return (-1);
	}
	else
	{
		if (ft_putchr(n + '0') == -1)
			return (-1);
		*i += 1;
	}
	return (*i);
}

static int	ft_putints(unsigned int n)
{
	int	i;

	i = 0;
	if (ft_putnbrs(n, &i) == -1)
		return (-1);
	return (i);
}

int	ft_putdec(unsigned int n)
{
	return (ft_putints(n));
}
