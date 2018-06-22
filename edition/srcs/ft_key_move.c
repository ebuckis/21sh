/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_key_move.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/22 15:58:05 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/22 16:02:05 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_edition.h"

int					ft_key_move(t_navig *n, char *buf)
{
	if (KEY_CODE_UP)
		n->y--;
	else if (KEY_CODE_DOWN)
		n->y++;
	else if (KEY_CODE_LEFT)
		ft_x_change(n, 0);
	else if (KEY_CODE_RIGHT)
		ft_x_change(n, 1);
	else if (KEY_CODE_END)
	{
		n->x = n->x_len;
		n->y = n->y_len;
	}
	else if (KEY_CODE_HOME)
	{
		n->x = n->x_start;
		n->y = n->y_start;
	}
	else
		return (0);
	return (1);
}
