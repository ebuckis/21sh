/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_key_alt.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/10 11:30:29 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/29 17:19:55 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_edition.h"

int		ft_alt_down(t_navig *n)
{
	if (n->y < n->y_len - 1 || (n->y == n->y_len - 1 && n->x <= n->x_len))
	{
		n->i += n->x_size;
		n->y++;
		ft_move_to_xy(n->x, n->y);
	}
	return (1);
}

int		ft_alt_up(t_navig *n)
{
	if (n->y > n->y_start + 1 || (n->y > n->y_start && n->x >= n->x_start))
	{
		n->i -= n->x_size;
		n->y--;
		ft_move_to_xy(n->x, n->y);
	}
	return (1);
}

int		ft_alt_left(t_navig *n)
{
	if (n->i > 0)
	{
		while (n->i > 0 && n->s[n->i - 1] == ' ')
			ft_x_change(n, MOVE_LEFT);
		while (n->i > 0 && n->s[n->i - 1] != ' ')
			ft_x_change(n, MOVE_LEFT);
	}
	return (1);
}

int		ft_alt_right(t_navig *n)
{
	if (n->i < (int)ft_strlen(n->s))
	{
		while (n->i < (int)ft_strlen(n->s) && n->s[n->i] != ' ')
			ft_x_change(n, MOVE_RIGHT);
		while (n->i < (int)ft_strlen(n->s) && n->s[n->i] == ' ')
			ft_x_change(n, MOVE_RIGHT);
	}
	return (1);
}

int		ft_key_alt(t_navig *n, char *buf)
{
	if (buf[4])
		return (1);
	if (buf[3] == 66)
		ft_alt_down(n);
	else if (buf[3] == 65)
		ft_alt_up(n);
	else if (buf[3] == 68)
		ft_alt_left(n);
	else if (buf[3] == 67)
		ft_alt_right(n);
	return (1);
}
