/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahernan <sahernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 13:37:59 by sahernan          #+#    #+#             */
/*   Updated: 2024/02/03 16:17:14 by sahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
/*int main()
{
	t_list *lst = NULL;
   	t_list *content1 = ft_lstnew("1");
	t_list *content2 = ft_lstnew("2");
	t_list *content3 = ft_lstnew("3");

	ft_lstadd_front(&lst, content3);
	ft_lstadd_front(&lst, content2);
	ft_lstadd_front(&lst, content1);
	printf("%d", ft_lstsize(lst));
}*/
