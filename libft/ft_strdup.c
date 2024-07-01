/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahernan <sahernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:39:54 by sahernan          #+#    #+#             */
/*   Updated: 2024/01/29 19:19:48 by sahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	size;
	char	*des;

	size = ft_strlen(src) + 1;
	des = malloc(size);
	if (!des)
		return (des);
	ft_strlcpy(des, src, size);
	return (des);
}
/*int main ()
{
	char a[] = "Santiago";
	printf("%s", a);
	return (0);	
}
*/
