/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahernan <sahernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:30:27 by sahernan          #+#    #+#             */
/*   Updated: 2024/01/29 16:31:29 by sahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;

	s1 = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (s1[i] == ((unsigned char)c))
			return (&s1[i]);
		i++;
	}
	return (0);
}
/*int main ()
{
	char a[] = "Santiago";	
	printf("%s", ft_memchr(a, 'a', 8));
	return (0);
}
*/
