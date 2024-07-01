/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahernan <sahernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:08:43 by sahernan          #+#    #+#             */
/*   Updated: 2024/01/29 19:19:29 by sahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*des;

	des = malloc(size * count);
	if (!des)
		return (0);
	ft_bzero(des, count * size);
	return (des);
}
/*int main ()
{
	char *a = ft_calloc(8, sizeof(char));
    printf("ft_alloc: %s", a);
}*/
