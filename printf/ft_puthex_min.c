/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_min.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahernan <sahernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:51:10 by sahernan          #+#    #+#             */
/*   Updated: 2024/02/12 18:42:51 by sahernan         ###   ########.fr       */
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

int	ft_puthex_min(unsigned int n)
{
	int	i;

	i = 0;
	if (ft_putnbrs(n, &i) == -1)
		return (-1);
	return (i);
}
