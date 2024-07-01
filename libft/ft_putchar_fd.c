/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahernan <sahernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:34:28 by sahernan          #+#    #+#             */
/*   Updated: 2024/01/29 19:27:08 by sahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <fcntl.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*int main ()
{
	int fd = open("test.txt", O_RDWR);
	printf("%d\n", fd);
	ft_putchar_fd('c', fd);
	close(fd);
	return (0);
}*/
