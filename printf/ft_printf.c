/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahernan <sahernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:23:49 by sahernan          #+#    #+#             */
/*   Updated: 2024/02/12 19:45:13 by sahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_type(va_list ap, const char *s)
{
	int	i;

	i = 0;
	if (*s == 'c')
		i = ft_putchr(va_arg(ap, int));
	else if (*s == 'd' || *s == 'i')
		i = ft_putint(va_arg(ap, int));
	else if (*s == 's')
		i = ft_putstr(va_arg(ap, char *));
	else if (*s == '%')
		i = ft_putchr('%');
	else if (*s == 'u')
		i = ft_putdec(va_arg(ap, int));
	else if (*s == 'x')
		i = ft_puthex_min(va_arg(ap, unsigned int));
	else if (*s == 'X' )
		i = ft_puthex_max(va_arg(ap, unsigned int));
	else if (*s == 'p')
		i = ft_putmem(va_arg(ap, unsigned long));
	return (i);
}

int	ft_printf(char const *s, ...)
{
	va_list	ap;
	int		count;
	int		var;

	va_start(ap, s);
	count = 0;
	while (*s != '\0')
	{
		if (*s == '%')
		{
			var = ft_check_type(ap, ++s);
			if (var == -1)
				return (-1);
			count += var;
		}
		else
		{
			if (ft_putchr(*s) == -1)
				return (-1);
			count++;
		}
		s++;
	}
	va_end(ap);
	return (count);
}

/*int main ()
{
	//char c = 'c';
	char *a;
	int n = 10;
	//char *s = "Simon el cabron";
	printf(" LENGTH: %d\n", ft_printf("Hola mundo %d", n));
	printf(" LENGTH: %d\n", printf("Hola mundo %d", n));
	//printf(" LENGTH: %s\n", NULL);
	//printf("%u\n", ft_printf("%u", -214748364));
	//printf("%u\n", printf("%u", -214748364));
	//printf("%x\n", n);
	//printf("LENGTH: %X", printf("%X\n", n));	
	//printf("\nLENGTH: %X", ft_printf("%X\n", n));	
	//printf("%p\n", a);
	//ft_printf("%p", a);
	return (0);
}*/
