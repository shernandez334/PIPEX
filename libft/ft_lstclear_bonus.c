/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahernan <sahernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:24:53 by sahernan          #+#    #+#             */
/*   Updated: 2024/02/04 18:44:50 by sahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone((*lst), del);
		(*lst) = tmp;
	}
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

	while(lst)
	{
		printf("%s", lst->content);
		lst = lst->next;
	}
	ft_lstclear(&lst, &free);
	
	printf("\nDespues:");
	while(lst)
	{
		printf("%s", lst->content);
		lst = lst->next;
	}
}*/
