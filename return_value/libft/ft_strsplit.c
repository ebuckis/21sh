/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <bpajot@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 14:35:53 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/07 15:14:10 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	*ft_index_begin_words(char const *s, size_t nb_word, char c)
{
	size_t	i;
	size_t	j;
	size_t	*index_begin_words;

	index_begin_words = (size_t*)malloc(sizeof(*index_begin_words) * nb_word);
	if (index_begin_words == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0' && j < nb_word)
	{
		if (i == 0 && s[i] != c)
		{
			index_begin_words[0] = 0;
			j++;
		}
		else if (i != 0 && s[i - 1] == c && s[i] != c)
		{
			index_begin_words[j] = i;
			j++;
		}
		i++;
	}
	return (index_begin_words);
}

static char		**ft_strsplit_2(char const *s, char c, char **tab,
		size_t *ind_words)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < ft_count_nb_words(s, c))
	{
		j = ind_words[i];
		while (s[j] != c && s[j] != '\0')
			j++;
		tab[i] = (char*)malloc(sizeof(*tab) * (j + 1 - ind_words[i]));
		if (tab[i] == NULL)
			return (NULL);
		j = ind_words[i];
		while (s[j] != c && s[j] != '\0')
		{
			tab[i][j - ind_words[i]] = s[j];
			j++;
		}
		tab[i][j - ind_words[i]] = '\0';
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	*ind_words;

	if (s == NULL)
		return (NULL);
	tab = (char**)malloc(sizeof(*tab) * (ft_count_nb_words(s, c) + 1));
	if (tab == NULL)
		return (NULL);
	ind_words = ft_index_begin_words(s, ft_count_nb_words(s, c), c);
	tab = ft_strsplit_2(s, c, tab, ind_words);
	ft_memdel((void**)&ind_words);
	return (tab);
}
