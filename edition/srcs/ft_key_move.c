/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_key_move.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/22 15:58:05 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/17 17:46:33 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_edition.h"

static int		ft_maj_stuct_nav(t_navig *n, char *str)
{
	char	*ret;
	int		calc;
	int		y_add;
	int		y_old;

	free(n->s);
	n->s = ft_strdup(str);
	ft_move_to_xy(n->x_start, n->y_start);//peut etre boucler jusqu'au debut si fenetre trop petite
	ret = NULL;
	if (!(ret = tgetstr("cd", NULL)))
		return (0);
	tputs(ret, 1, ft_putcharint);
	calc = ft_strlen(n->prompt) + ft_strlen(n->s) + 1;
	y_add = 1 + (calc / (n->x_size + 1));
	y_old = n->y_first;
	ft_putstr(n->s);
	n->i = ft_strlen(n->s);
	ft_recup_pos(&(n->x), &(n->y));
	ft_recup_pos(&(n->x_len), &(n->y_len));
	if ((calc - 1) % n->x_size == 0)
	{
		if (n->y == n->y_size - 1)
		{
			dprintf(2, "__________der line________\n");
			if (!(ret = tgetstr("sf", NULL)))
				return (0);
			tputs(ret, 1, ft_putcharint);
		}
		else
		{
			n->y++;
			n->y_len++;
		}
		n->x = 0;
		n->x_len = 0;
		y_add++;
	}
	if (y_old + y_add > n->y_size)
	{
		n->y_first -= (y_old + y_add - n->y_size);
		n->y_start -= (y_old + y_add - n->y_size);
	}
	return (1);
}

//	dprintf(2, "\n----------------------------\ncalc = ft_strlen(n->prompt) + ft_strlen(n->s) + 1;\n%d = %zu + %zu + 1\n-----------------------\n" , calc, ft_strlen(n->prompt), ft_strlen(n->s));
//	dprintf(2, "\n----------------------------\ny_add = 1 + (calc / (n->x_size + 1));\n%d = 1 + (%d / %d + 1)\n-----------------------\n", y_add, calc, n->x_size);
//	dprintf(2, "\n++++++++++++++++++++++++++++\nx = %d\nx_size = %d\nx_len = %d\n+++++++++++++++++++++++++\n", n->x, n->x_size, n->x_len);

int				ft_key_move(t_navig *n, char *buf)
{
	char	*str;

	if (KEY_CODE_UP)
	{
		str = ft_give_hist(1, NULL);
		if (str)
		{
			if (n->id_hist == 0)
				n->s_save = ft_strdup(n->s);
			ft_maj_stuct_nav(n, str);
			n->id_hist++;
		}
	}
	else if (KEY_CODE_DOWN)
	{
		str = ft_give_hist(-1, NULL);
		if (str)
		{
			ft_maj_stuct_nav(n, str);
			n->id_hist--;
		}
		else if (n->id_hist == 1)
		{
			ft_maj_stuct_nav(n, n->s_save);
			n->s_save = NULL;
			n->id_hist--;
		}
	}
	else if (KEY_CODE_LEFT)
		ft_x_change(n, MOVE_LEFT);
	else if (KEY_CODE_RIGHT)
		ft_x_change(n, MOVE_RIGHT);
	else if (KEY_CODE_END)
	{
		n->x = n->x_len;
		n->y = n->y_len;
		n->i = ft_strlen(n->s);
	}
	else if (KEY_CODE_HOME)
	{
		n->x = n->x_start;//boucler pour arriver au debut
		n->y = n->y_start;
		n->i = 0;
	}
	else
		return (0);
	return (1);
}

/*
** a mettre en place :
** - Historique de navigation
** a voir comment gerer le copier coller
*/