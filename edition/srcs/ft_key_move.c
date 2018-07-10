/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_key_move.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/22 15:58:05 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/10 11:40:40 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_edition.h"

int					ft_key_move(t_navig *n, char *buf)
{
	if (KEY_CODE_UP)
		n->y = n->y;//modif naviguer historique
	else if (KEY_CODE_DOWN)
		n->y = n->y;//modif naviguer historique
	else if (KEY_CODE_LEFT)
		ft_x_change(n, MOVE_LEFT);
	else if (KEY_CODE_RIGHT)
		ft_x_change(n, MOVE_RIGHT);
	else if (KEY_CODE_END)
	{
		n->x = n->x_len;
		n->y = n->y_len;
		n->i = ft_strlen(n->s);
	}
	else if (KEY_CODE_HOME)
	{
		n->x = n->x_start;
		n->y = n->y_start;
		n->i = 0;
	}
	else
		return (0);
	return (1);
}
/*
** a mettre en place :
** - Historique de navigation
** - ctrl fleches (haut ou bas) on change de ligne
** a voir comment gerer le copier coller
*/