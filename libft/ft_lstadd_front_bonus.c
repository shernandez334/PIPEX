/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahernan <sahernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 21:37:21 by sahernan          #+#    #+#             */
/*   Updated: 2024/02/05 11:31:03 by sahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *n)
{
	if (*lst)
		n->next = *lst;
	*lst = n;
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

	while (lst)
	{
		printf("%s", lst->content);
		lst = lst->next;
	}
}*/
