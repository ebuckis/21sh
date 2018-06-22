/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init_nav.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/22 15:48:03 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/22 17:12:20 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_edition.h"

void		ft_init_nav(t_navig *n)
{
	ft_get_size(&(n->x_size), &(n->y_size));
	ft_recup_pos(&(n->x_start), &(n->y_start));//recupere la position actuelle
	n->x = n->x_start;
	n->y = n->y_start;
	n->x_len = n->x_start;
	n->y_len = n->y_start;
}
