/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_del_char.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/26 08:41:29 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/29 13:46:33 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_edition.h"

static char	*ft_supprchar(char *s, int i)
{
	int		n;
	int		j;
	char	*str;

	n = ft_strlen(s);
	j = 0;
	if (!(str = ft_strnew(n)))
		return (NULL);
	while (j < i - 1)
	{
		str[j] = s[j];
		j++;
	}
	while (j < n - 1)
	{
		str[j] = s[j + 1];
		j++;
	}
	str[n - 1] = '\0';
	ft_strdel(&s);
	s = str;
	return (s);
}

int			ft_del_char(t_navig *n)
{
	char	*res;

	if (n->i != 0)
	{
		if (!(n->s_aff = ft_supprchar(n->s_aff, n->i - 1)))
			return (0);
		if (!(n->s_save = ft_supprchar(n->s_save, n->i - 1)))
			return (0);
//printf("\n ______________________ \n");
//printf("i = %d                                       \n", n->i);
//printf("x = %d                                       \n", n->x);
//printf("y = %d                                       \n", n->y);
//printf("s_aff = %s                                   \n", n->s_aff);
//printf("s_aff = %s                                   \n", n->s_aff + n->i);
		ft_x_change(n, CHAR_SUPPR);
		res = tgetstr("cm", NULL);
		tputs(tgoto(res, n->x, n->y), 1, ft_putcharint);
		ft_maj_line(n, -1);
	}
	return (1);
}
