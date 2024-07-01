/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_ppx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:26:25 by sahernan          #+#    #+#             */
/*   Updated: 2024/06/28 17:56:58 by sahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strjoin_ppx(char *s1, char *s2)
{
	size_t  total_size;
	size_t  j;
	size_t  i;
    char    *dest;
 
	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	total_size = ft_strlen(s1) + ft_strlen(s2);
	dest = malloc(total_size + 1);
	if (!dest) 
		return (0); 
	while (s1[i] != '\0')
	{   
        dest[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		dest[i++] = s2[j++];
	dest[i] = '\0';
	free(s1);
    return (dest);
}   
