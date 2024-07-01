/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahernan <sahernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:18:58 by sahernan          #+#    #+#             */
/*   Updated: 2024/02/03 17:30:19 by sahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*int main ()
{	
	t_list *lst = NULL;
	t_list *content1 = ft_lstnew("1");
	t_list *content2 = ft_lstnew("2");
	t_list *content3 = ft_lstnew("3");

	ft_lstadd_front(&lst, content3);
	ft_lstadd_front(&lst, content2);
	ft_lstadd_front(&lst, content1);
	
	t_list *lstlast = ft_lstlast(lst);

	printf("%s", lstlast->content);
}*/
