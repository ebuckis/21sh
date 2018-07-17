/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_move_to_xy.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/29 16:13:30 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/17 18:39:35 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_edition.h"

int		ft_move_to_xy(int x, int y)
{
	char		*res;

	if (!(res = tgetstr("cm", NULL)))
		return (0);
	tputs(tgoto(res, x, y), 1, ft_putcharint);
	return (1);
}
