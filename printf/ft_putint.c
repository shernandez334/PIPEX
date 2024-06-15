/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahernan <sahernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:17:44 by sahernan          #+#    #+#             */
/*   Updated: 2024/02/12 13:34:16 by sahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

static int	ft_putnbrspc(int *n, int *i)
{
	if (*n == -2147483648)
	{
		if (ft_putstr("-2") == -1)
			return (-1);
		*i += 2;
		*n = 147483648;
		return (*i);
	}
	else
	{
		if (ft_putchr('-') == -1)
			return (-1);
		*n *= -1;
		*i += 1;
		return (*n);
	}
}

static int	ft_putnbr(int n, int *i)
{
	if (n == -2147483648)
	{
		if (ft_putnbrspc(&n, i) == -1)
			return (-1);
	}
	if (n < 0)
	{
		if (ft_putnbrspc(&n, i) == -1)
			return (-1);
	}
	if (n > 9)
	{
		if (ft_putnbr(n / 10, i) == -1)
			return (-1);
		if (ft_putnbr(n % 10, i) == -1)
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

int	ft_putint(int n)
{
	int	i;

	i = 0;
	if (ft_putnbr(n, &i) == -1)
		return (-1);
	return (i);
}
