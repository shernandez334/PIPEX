/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahernan <sahernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 09:44:10 by sahernan          #+#    #+#             */
/*   Updated: 2024/01/29 19:26:07 by sahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	str = (char *)malloc(ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*char ft_function(unsigned int i, char str)
{
	printf("Index: %d\n and String: %c\n", i, str);
	return (str - 32);
}

int main()
{
	char str[]= "hello world\n";
	printf("The result is: %s", str);
	char *result =  ft_strmapi(str, ft_function);
	printf("%s", result);
	return (0);
}*/
