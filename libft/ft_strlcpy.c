/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahernan <sahernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:16:59 by sahernan          #+#    #+#             */
/*   Updated: 2024/01/29 19:11:19 by sahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	size;
	size_t	i;

	i = 0;
	size = 0;
	while (src[size] != '\0')
		size++;
	if (dstsize == 0)
		return (size);
	while (src[i] != '\0' && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (size);
}

/*int main ()
{
	char dst [26];
	char src [] = "lorem ipsum dolor sit amet";
	size_t dstsize = 4;
	
	printf(" Strlcpy: %zu\n", strlcpy(dst, src, dstsize));
    printf("%s", dst);
	
	printf(" Strlcpy: %zu\n", ft_strlcpy(dst, src, dstsize));
	printf("%s", dst);
}
*/
