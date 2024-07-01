/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahernan <sahernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:20:03 by sahernan          #+#    #+#             */
/*   Updated: 2024/02/04 18:33:00 by sahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *n)
{
	t_list	*lstlast;

	if (*lst)
	{
		lstlast = ft_lstlast(*lst);
		lstlast->next = n;
	}
	else
		*lst = n;
}
/*int main()
{
	t_list *lst = NULL;
	t_list *content1 = ft_lstnew("1");
    t_list *content2 = ft_lstnew("2");
    t_list *content3 = ft_lstnew("3");
	t_list *n = ft_lstnew("4");

    ft_lstadd_front(&lst, content3);
    ft_lstadd_front(&lst, content2);
    ft_lstadd_front(&lst, content1);

	ft_lstadd_back(&lst, n);
	while (lst->next)
		lst = lst->next;
	printf("%s", lst->content);
}*/
