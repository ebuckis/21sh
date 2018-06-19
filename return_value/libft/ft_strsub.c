/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 14:36:08 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/21 14:36:10 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*p;

	if (s != NULL)
	{
		p = ft_strnew(len);
		if (p == NULL)
			return (NULL);
		if (len == 0)
			p[0] = '\0';
		else
			p = ft_strncpy(p, &s[start], len);
		return (p);
	}
	else
		return (NULL);
}
