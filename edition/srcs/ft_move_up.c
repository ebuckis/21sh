/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_move_up.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/03 15:55:23 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/04 18:36:00 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_edition.h"

int		ft_move_up(t_navig *n)
{
	printf("\n\n\n\n\n");
	if (!(ret = tgetstr("sc", NULL)))
		return (0);
	tputs(ret, 1, ft_putcharint);
	if (!(ret = tgetstr("vi", NULL)))
		return (0);
	tputs(ret, 1, ft_putcharint);
	ft_move_to_xy(nav.x, nav.y);
	if (!(ret = tgetstr("sf", NULL)))
		return ;
	ft_move_to_xy(nav.x, nav.y);
	tputs(ret, 1, ft_putcharint);
	if (!(ret = tgetstr("ve", NULL)))
		return (0);
	tputs(ret, 1, ft_putcharint);
	if (!(ret = tgetstr("rc", NULL)))
		return (0);
	tputs(ret, 1, ft_putcharint);
}
