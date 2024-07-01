/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahernan <sahernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:52:39 by sahernan          #+#    #+#             */
/*   Updated: 2024/01/30 10:56:21 by sahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		(*f)(i, s + i);
		i++;
	}
}
/*void ft_myfunction(unsigned int i, char *str)
{
	printf("Index: %d, Char: %c\n", i, str[i]);
}

void	ft(unsigned int i, char *str)
{
	str[i] = toupper(str[i]);
}

int main ()
{
	char str[] = "Santiago\n";
	printf("Antes: %s", str);
	ft_striteri(str, ft_myfunction);
	printf("Despues: %s\n", str);
	return (0);
}*/
