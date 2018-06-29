/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_new_char.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/25 16:34:29 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/28 16:50:27 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_edition.h"

static char	*ft_addchar(char *s, char c, int i)
{
	int		n;
	int		j;
	char	*str;

	n = ft_strlen(s);
	j = 0;
	if (!(str = ft_strnew(n + 1)))//verifier la taille des malloc
		return (NULL);
	while (j < i)
	{
		str[j] = s[j];
		j++;
	}
	str[j] = c;
	j++;
	while (j < n + 1)
	{
		str[j] = s[j - 1];
		j++;
	}
	ft_strdel(&s);
	s = str;
	return (s);
}

int			ft_new_char(t_navig *n, char *buf)
{
	if (!(n->s_aff = ft_addchar(n->s_aff, buf[0], n->i)))
		return (0);
	if (!(n->s_save = ft_addchar(n->s_save, buf[0], n->i)))
		return (0);
	//printf("%s\n", n->s_aff);
	if (!ft_maj_line(n, 1))
		return (0);
	ft_x_change(n, CHAR_AJOUT);
	return (1);
}
