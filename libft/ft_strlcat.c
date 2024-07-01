/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahernan <sahernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:15:33 by sahernan          #+#    #+#             */
/*   Updated: 2024/01/29 16:13:48 by sahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	size_src;
	size_t	size_dst;
	size_t	total_size;
	size_t	i;

	size_src = ft_strlen(src);
	size_dst = ft_strlen(dst);
	total_size = size_src + size_dst;
	i = 0;
	if (dstsize < size_dst + 1)
		return (dstsize + size_src);
	if (dstsize > size_dst + 1)
	{
		while (src[i] != '\0' && i + size_dst + 1 < dstsize)
		{
			dst[size_dst + i] = src[i];
			i++;
		}
	}
	dst[size_dst + i] = '\0';
	return (total_size);
}
/*int main ()
{
	char src[] = "Hernandez";
	char dst[] = "Santiago";
	size_t a = ft_strlcat(dst, src, 10);
	printf("%s\n", dst);
	printf("%zu", a);
}
*/
