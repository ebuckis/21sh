/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_gestion_signal.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/25 12:57:00 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/09/03 15:54:59 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_edition.h"

void		ft_signal_size(int s)
{
	(void)s;
	ft_maj_win(&g_nav);
}

/*
** gestion du resize win via la variable globale
*/
