/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahernan <sahernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:33:34 by sahernan          #+#    #+#             */
/*   Updated: 2024/02/01 16:49:49 by sahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countwords(char const *s, char c)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			len++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			while (s[i] == c)
				i++;
	}
	return (len);
}

static int	ft_next_word(char const *s, int *i, char c)
{
	while (s[*i] == c && s[*i])
		(*i)++;
	return (*i);
}

static int	ft_word_size(char const *s, int i, char c)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		i++;
		size++;
	}
	return (size);
}

static void	ft_free_all(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		words;
	int		i;
	int		word_size;
	int		word_count;

	words = ft_countwords(s, c);
	strs = malloc(sizeof(char *) * (words + 1));
	if (!strs)
		return (0);
	word_count = 0;
	i = 0;
	while (word_count < words)
	{
		i = ft_next_word(s, &i, c);
		word_size = ft_word_size(s, i, c);
		strs[word_count] = ft_substr(s, i, word_size);
		if (!strs[word_count])
			return (ft_free_all(strs), NULL);
		i += word_size;
		word_count++;
	}
	strs[word_count] = NULL;
	return (strs);
}
/*int main ()
{
	char **str = ft_split("Hello", ' ');

	while(*str)
		printf("%s\n", *str++);
	return (0);
}*/
