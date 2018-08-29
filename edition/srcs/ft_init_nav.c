/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init_nav.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/22 15:48:03 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/29 13:53:23 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_edition.h"

int			ft_init_nav(t_navig *n, char *p)
{
	int		x_tmp;

	ft_recup_pos(&x_tmp, &(n->y_first));
	ft_recup_pos(&x_tmp, &(n->y_first));
	ft_putstr(p);
	n->to_small = 0;
	n->prompt = p;
	if (!(ft_get_size(&(n->x_size), &(n->y_size))))
		return (0);
	ft_recup_pos(&(n->x_start), &(n->y_start));
	ft_recup_pos(&(n->x), &(n->y));
	n->i = 0;
	n->x_len = n->x_start;
	n->y_len = n->y_start;
	if (!(n->s = ft_strdup("\0")))
		return (0);
	n->s_save = NULL;
	n->id_hist = 0;
	if (!(ft_open_hist()))
		return (0);
	if (!(ft_move_to_xy(n->x_start, n->y_start)))
		return (0);
	n->err = 1;
	return (1);
}

/*
** rajouter de la couleur pour le prompt ?
*/
