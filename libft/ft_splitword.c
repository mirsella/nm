/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 23:13:50 by mirsella          #+#    #+#             */
/*   Updated: 2023/02/07 21:36:59 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_words(const char *s, const char *word)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && ft_strncmp(&s[i], word, ft_strlen(word)) == 0)
			i += ft_strlen(word);
		if (s[i] && ft_strncmp(&s[i], word, ft_strlen(word)) != 0)
			count++;
		while (s[i] && ft_strncmp(&s[i], word, ft_strlen(word)) != 0)
			i++;
	}
	return (count);
}

static char	*getword(const char *s, int i, const char *word)
{
	char	*res;
	int		j;
	int		wordlen;

	j = 0;
	wordlen = 0;
	while (s[i + wordlen]
		&& ft_strncmp(&s[i + wordlen], word, ft_strlen(word)) != 0)
		wordlen++;
	res = malloc(sizeof(char) * wordlen + 1);
	if (!res)
		return (NULL);
	while (s[i] && ft_strncmp(&s[i], word, ft_strlen(word)) != 0)
	{
		res[j] = s[i];
		i++;
		j++;
	}
	res[j] = 0;
	return (res);
}

char	**ft_splitword(const char *s, const char *word)
{
	int		i;
	int		wordcount;
	char	**tab;

	tab = ft_calloc(sizeof(char *), (count_words(s, word) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	wordcount = 0;
	while (s[i])
	{
		while (s[i] && ft_strncmp(&s[i], word, ft_strlen(word)) == 0)
			i += ft_strlen(word);
		if (s[i])
		{
			tab[wordcount] = getword(s, i, word);
			if (!tab[wordcount])
				return (ft_free_tab(tab), NULL);
			wordcount++;
		}
		while (s[i] && ft_strncmp(&s[i], word, ft_strlen(word)) != 0)
			i++;
	}
	tab[wordcount] = 0;
	return (tab);
}
