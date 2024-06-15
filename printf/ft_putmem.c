/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahernan <sahernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:51:55 by sahernan          #+#    #+#             */
/*   Updated: 2024/02/13 14:36:46 by sahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbrs(unsigned long n, int *i)
{
	if (n <= 9)
	{
		if (ft_putchr(n + 48) == -1)
			return (-1);
		*i += 1;
	}
	else if (n <= 15)
	{
		if (ft_putchr((n -10) + 'a') == -1)
			return (-1);
		*i += 1;
	}
	else
	{
		if (ft_putnbrs(n / 16, i) == -1)
			return (-1);
		if (ft_putnbrs(n % 16, i) == -1)
			return (-1);
	}
	return (*i);
}

static int	ft_puthex_mins(unsigned long n)
{
	int	i;

	i = 0;
	if (ft_putnbrs(n, &i) == -1)
		return (-1);
	return (i);
}

int	ft_putmem(unsigned long n)
{
	int	i;
	int	y;

	i = 2;
	if (ft_putstr("0x") == -1)
		return (-1);
	y = ft_puthex_mins(n);
	if (y == -1)
		return (-1);
	i += y;
	return (i);
}
