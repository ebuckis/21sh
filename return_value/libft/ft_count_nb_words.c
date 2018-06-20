/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_count_nb_words.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 14:28:17 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/04 20:07:48 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_count_nb_words(char const *s, char c)
{
	size_t		i;
	size_t		nb_word;

	if (s != NULL && ft_strlen(s) > 0)
	{
		i = 0;
		while (s[i] != '\0')
		{
			if (i == 0)
			{
				if (s[i] == c)
					nb_word = 0;
				else
					nb_word = 1;
			}
			else if ((s[i - 1] == c) && s[i] != c)
				nb_word++;
			if (nb_word == 2147483647)
				return (0);
			i++;
		}
		return (nb_word);
	}
	return (0);
}
