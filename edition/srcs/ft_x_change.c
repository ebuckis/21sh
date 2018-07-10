/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_x_change.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/22 15:54:46 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/10 15:17:15 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_edition.h"

static void		ft_move_right_x(t_navig *n)
{
	if (n->y == n->y_size - 1 && n->x >= n->x_size - 1)
	{
		n->x = 0;
		n->y++;
	}
	else if (n->y < n->y_len && n->x < n->x_size - 1)
		n->x++;
	else if (n->x < n->x_len)
		n->x++;
	else if (n->y < n->y_len)
	{
		n->x = 0;
		n->y++;
	}
	else
		return ;
	n->i++;
}

static void		ft_move_left_x(t_navig *n)
{
	if (n->y > n->y_start && n->x > 0)
		n->x--;
	else if (n->y > n->y_start)
	{
		n->x = n->x_size - 1;
		n->y--;
	}
	else if (n->x > n->x_start)
		n->x--;
	else
		return ;
	n->i--;
}

static void		ft_del_x(t_navig *n)
{
	if (n->y_len > n->y_start && n->x_len > 0)
		n->x_len--;
	else if (n->y_len > n->y_start)
	{
		n->x_len = n->x_size;
		n->y_len--;
	}
	else if (n->x_len > n->x_start)
		n->x_len--;
	else
		return ;
	ft_move_left_x(n);
}

static void		ft_add_x(t_navig *n)
{
	char *ret;

	if (n->x_len < n->x_size - 1)
		n->x_len++;
	else if (n->y_len < n->y_size - 1)
	{
		n->x_len = 0;
		n->y_len++;
	}
	else if (n->y_len >= n->y_size - 1)
	{
		ft_move_up(n);
		n->x_len = 0;
		n->y_first--;
		n->y_start--;
		n->y--;
	}
	else
		return ;
	ft_move_right_x(n);
}

void		ft_x_change(t_navig *n, int i)
{
	if (i == CHAR_AJOUT)
		ft_add_x(n);
	else if (i == CHAR_SUPPR)
		ft_del_x(n);
	else if (i == MOVE_RIGHT)
		ft_move_right_x(n);
	else if (i == MOVE_LEFT)
		ft_move_left_x(n);
}
