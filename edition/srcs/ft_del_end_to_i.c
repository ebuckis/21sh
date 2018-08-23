/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_del_end_to_i.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/25 19:04:13 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/23 17:56:09 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_edition.h"

void		ft_del_end_to_i(t_navig *n)
{
	char	buf[5];
	int		i;

	ft_bzero(buf, 5);
	buf[0] = 127;
	i = n->i;
	ft_move_to_xy(n->x_len, n->y_len);
	n->x = n->x_len;
	n->y = n->y_len;
	n->i = ft_strlen(n->s);
	while (n->i != i)
		ft_key_code(n, buf);
	dprintf(2, "______________\n	i : %d\n	x : %d\n	y : %d\n	x_len : %d\n	y_len : %d\n______________\n", n->i, n->x, n->y, n->x_len, n->y_len);
}

/*
** pb quand on del char sur du multi line voir ft_del char && ft_x_change(CHAR_SUPPR)
*/