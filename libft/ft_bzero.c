/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahernan <sahernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:27:23 by sahernan          #+#    #+#             */
/*   Updated: 2024/01/29 19:09:30 by sahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((unsigned char *)s)[i++] = '\0';
}

/*int main ()
{
	char s[] = "123456789012345";
	size_t n= 10;
	printf("Antes: %s\n", s);
	bzero(s, n);
	printf("Despues: %s\n", s);
}
*/
