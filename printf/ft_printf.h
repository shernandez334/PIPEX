/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahernan <sahernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:51:07 by sahernan          #+#    #+#             */
/*   Updated: 2024/02/12 19:24:36 by sahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(char const *s, ...);
int	ft_putchr(char c);
int	ft_putstr(char *str);
int	ft_putint(int n);
int	ft_putdec(unsigned int n);
int	ft_puthex_min(unsigned int n);
int	ft_puthex_max(unsigned int n);
int	ft_putmem(unsigned long n);

#endif
