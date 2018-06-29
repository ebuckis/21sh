/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init_nav.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/22 15:48:03 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/26 13:00:08 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_edition.h"

int			ft_init_nav(t_navig *n)
{
	ft_get_size(&(n->x_size), &(n->y_size));
	ft_recup_pos(&(n->x_start), &(n->y_start));//recupere la position actuelle
	ft_recup_pos(&(n->x), &(n->y));//recupere la position actuelle
	n->i = 0;
	n->x_len = n->x_start;
	n->y_len = n->y_start;
	if (!(n->s_aff = ft_strdup("\0")))
		return (0);
	if (!(n->s_save = ft_strdup("\0")))
		return (0);
	return (1);
}
