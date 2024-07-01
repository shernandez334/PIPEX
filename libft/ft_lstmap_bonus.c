/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahernan <sahernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 20:13:37 by sahernan          #+#    #+#             */
/*   Updated: 2024/02/05 10:21:19 by sahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*n;
	void	*data;

	tmp = NULL;
	if (!f || !del)
		return (0);
	while (lst)
	{
		data = (*f)(lst->content);
		n = ft_lstnew(data);
		if (!n)
		{
			free(data);
			ft_lstclear(&tmp, del);
		}
		ft_lstadd_back(&tmp, n);
		lst = lst->next;
	}
	return (tmp);
}
/*static void	*tolower(void *str)
{
	 int i = 0;

	 char *s = (char *)str;
	 printf("%s\n", s);
	 while (s[i])
	 {
		 if (s[i] >= 'A' && s[i] <= 'Z')
			 s[i] =  s[i] + 32;
		 i++;
	 }
	 return (s);
}

int main()
{
	char cont1[] = "ABC";
	char cont2[] = "EFG";
	
	t_list *lst = NULL;
	t_list *content1 = ft_lstnew(cont1);
	t_list *content2 = ft_lstnew(cont2);

	ft_lstadd_front(&lst, content2);
	ft_lstadd_front(&lst, content1);

	t_list *tmp = lst; 
	
	while (lst)
	{
		printf("%s", lst->content);
		lst = lst->next;
	}

	ft_lstmap(tmp, tolower, &free);
	while (tmp)
	{
		 printf("\n%s", tmp->content);
		 tmp = tmp->next;
	}
}*/
