/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahernan <sahernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 13:19:49 by sahernan          #+#    #+#             */
/*   Updated: 2024/02/05 11:49:51 by sahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

/*:static void	tolower(void *str)
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
}
int main()
{
	t_list *lst 		= NULL;
	char	con1[] = "ABCD";
	char	con2[] = "EFGH";
	t_list *content1 	= ft_lstnew(con1);
	t_list *content2 	= ft_lstnew(con2);

	ft_lstadd_front(&lst, content2);
	ft_lstadd_front(&lst, content1);
	
	t_list *tmp = lst;

	while (tmp)
	{
		printf("%s", tmp->content);
		tmp = tmp->next;
	}
	
	tmp = lst;
	
	ft_lstiter(tmp, tolower);
	while (lst)
	{
		printf("\n%s", lst->content);
		lst = lst->next;
	}
}*/
