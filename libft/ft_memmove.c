/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahernan <sahernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:21:29 by sahernan          #+#    #+#             */
/*   Updated: 2024/01/29 16:03:55 by sahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = len;
	if (dst == src)
		return (dst);
	if (dst > src)
	{
		while (i > 0)
		{
			((unsigned char *)dst)[i - 1] = ((unsigned char *)src)[i - 1];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}
/*int main ()
{
	char src1[20] = "Santiago";
	char src2[20] = "Santiago";
	
	size_t e = 8 * sizeof(char);
	printf("memmove: %s\n", (memmove(src1 + 2, src1, e)));
	printf("Own: %s", (ft_memmove(src2 + 2, src2, e)));
	return (0);
}
*/
