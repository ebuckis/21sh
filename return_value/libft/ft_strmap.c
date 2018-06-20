/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 14:34:38 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/21 14:34:40 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*p;
	size_t	i;

	i = 0;
	if (s != NULL && ft_strlen(s) > 0 && f != NULL)
	{
		p = ft_strnew(ft_strlen(s));
		if (p == NULL)
			return (NULL);
		while (i < ft_strlen(s))
		{
			p[i] = f(s[i]);
			i++;
		}
		return (p);
	}
	else
		return (NULL);
}
