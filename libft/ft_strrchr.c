/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahernan <sahernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:29:31 by sahernan          #+#    #+#             */
/*   Updated: 2024/01/29 19:14:09 by sahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (0);
}
/*int main ()
{
	char a[] = "Santiago";
	char *c = ft_strrchr(a, 'o');	
	printf("ft_strrch: %s\n", c);

	char *d = strrchr(a, 'o');
	printf("strrch: %s", d);
	return (0);
}
*/
