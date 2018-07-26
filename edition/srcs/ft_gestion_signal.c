/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_gestion_signal.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/25 12:57:00 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/26 13:29:58 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_edition.h"

void		ft_signal_size(int s)
{
	(void)s;
	dprintf(2, "on est sur un resize: |%d|\n", s);
	ft_maj_win(&g_nav);
}
