/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_x_change.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/22 15:54:46 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/05 11:33:15 by kcabus      ###    #+. /#+    ###.fr     */
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

int		ft_move_up(t_navig *n)//fonction dans un autre fichier
{
	char	*ret;

	ft_move_to_xy(n->x_len, n->y_len);
	if (!(ret = tgetstr("sf", NULL)))
		return (0);
	tputs(ret, 1, ft_putcharint);
	ft_move_to_xy(n->x, n->y);
	ft_move_to_xy(n->x, n->y);
	return (1);
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
//	printf("\n______________________\n");
//	printf("i = %d\n", n->i);
//	printf("x = %d\n", n->x);
//	printf("y = %d\n", n->y);
//	printf("x_len = %d\n", n->x_len);
//	printf("y_len = %d\n", n->y_len);
//	printf("x_start = %d\n", n->x_start);
//	printf("y_start = %d\n", n->y_start);
//	printf("x_size = %d\n", n->x_size);
//	printf("y_size = %d\n", n->y_size);
//	printf("s_aff = %s\n", n->s_aff);
//	printf("s_aff = %s\n", n->s_aff + n->i);
	if (i == CHAR_AJOUT)
		ft_add_x(n);
	else if (i == CHAR_SUPPR)
		ft_del_x(n);
	else if (i == MOVE_RIGHT)
		ft_move_right_x(n);
	else if (i == MOVE_LEFT)
		ft_move_left_x(n);
//	printf("\n\n  ______________________\n");
//	printf("i = %d\n", n->i);
//	printf("x = %d\n", n->x);
//	printf("y = %d\n", n->y);
//	printf("x_len = %d\n", n->x_len);
//	printf("y_len = %d\n", n->y_len);
//	printf("x_start = %d\n", n->x_start);
//	printf("y_start = %d\n", n->y_start);
//	printf("x_size = %d\n", n->x_size);
//	printf("y_size = %d\n", n->y_size);
//	printf("s_aff = %s\n", n->s_aff);
//	printf("s_aff = %s\n", n->s_aff + n->i);

}

//	printf("adress x = %d\n", &(n->x));
//	printf("x = %d\n", n->x);
//	printf("y = %d\n", n->y);
//	printf("x_len = %d\n", n->x_len);
//	printf("y_len = %d\n", n->y_len);
//	printf("x_start = %d\n", n->x_start);
//	printf("y_start = %d\n", n->y_start);
//	printf("x_size = %d\n", n->x_size);
//	printf("y_size = %d\n", n->y_size);
// i == 1 -> ++ else -- if 2 on peut aller plus loin
