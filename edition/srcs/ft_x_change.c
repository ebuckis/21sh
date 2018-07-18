/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_x_change.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/22 15:54:46 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/18 13:18:24 by kcabus      ###    #+. /#+    ###.fr     */
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
	if (n->i > 0)
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
	dprintf(2, "\n*******************\ni : %d\nx : %d\ny : %d\nx_len : %d\ny_len : %d\nx_start : %d\ny_start : %d\nx_size : %d\ny_size : %d\n******************************\n", n->i, n->x, n->y, n->x_len, n->y_len, n->x_start, n->y_start, n->x_size, n->y_size);
}
