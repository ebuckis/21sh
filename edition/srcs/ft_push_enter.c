/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_push_enter.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/13 13:55:34 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/17 14:21:44 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#include "ft_edition.h"

int		ft_push_enter(t_navig *n)
{
	char		*tmp;

	dprintf(2, "debut de push enter\n");
	if (!(ft_move_to_xy(n->x_len, n->y_len)))
		return (0);
	dprintf(2, "push enter : ft_move ok\n");
	ft_putstr("\n");
	if (!n->s)
		return (0);
	if (n->s && (tmp = ft_whitespace(n->s)))
	{
		dprintf(2, "push enter : s existe et white ok\n");
		free(tmp);
		if (!(ft_add_hist(n->s)))
			return (0);
	}
	else if (n->s)
	{
		dprintf(2, "push enter : s existe et white  pas ok\n");
		ft_strdel(&(n->s));
		return (0);
	}
	dprintf(2, "Tout ok\n");
	return (1);
}
