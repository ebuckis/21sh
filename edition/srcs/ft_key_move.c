/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_key_move.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/22 15:58:05 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/25 19:01:45 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_edition.h"

static int		ft_re_print_s(t_navig *n, int *y_add, int calc)
{
	char	*ret;

	ft_putstr(n->s);
	n->i = ft_strlen(n->s);
	ft_recup_pos(&(n->x), &(n->y));
	ft_recup_pos(&(n->x_len), &(n->y_len));
	if ((calc - 1) % n->x_size == 0)
	{
		if (n->y == n->y_size - 1)
		{
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
		(*y_add)++;
	}
	return (1);
}

static int		ft_maj_stuct_nav(t_navig *n, char *str)
{
	char	*ret;
	int		calc;
	int		y_add;
	int		y_old;

	free(n->s);
	n->s = ft_strdup(str);
	ft_move_to_xy(n->x_start, n->y_start);
	if (!(ret = tgetstr("cd", NULL)))
		return (0);
	tputs(ret, 1, ft_putcharint);
	calc = ft_strlen(n->prompt) + ft_strlen(n->s) + 1;
	y_add = 1 + (calc / (n->x_size + 1));
	y_old = n->y_first;
	ft_re_print_s(n, &y_add, calc);
	if (y_old + y_add > n->y_size)
	{
		n->y_first -= (y_old + y_add - n->y_size);
		n->y_start -= (y_old + y_add - n->y_size);
	}
	return (1);
}

static void		ft_down_hist(t_navig *n)
{
	char	*str;

	str = NULL;
	str = ft_give_hist(-1, NULL);
	if (str)
	{
		ft_maj_stuct_nav(n, str);
		n->id_hist--;
	}
	else if (n->id_hist == 1)
	{
		ft_maj_stuct_nav(n, n->s_save);
		free(n->s_save);
		n->s_save = NULL;
		n->id_hist--;
	}
}

static void		ft_up_hist(t_navig *n)
{
	char	*str;

	str = NULL;
	str = ft_give_hist(1, NULL);
	if (str)
	{
		if (n->id_hist == 0)
			n->s_save = ft_strdup(n->s);
		ft_maj_stuct_nav(n, str);
		n->id_hist++;
	}
}

int				ft_key_move(t_navig *n, char *buf)
{
	if (KEY_CODE_UP)
		ft_up_hist(n);
	else if (KEY_CODE_DOWN)
		ft_down_hist(n);
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
		n->x = n->x_start;
		n->y = n->y_start;
		n->i = 0;
	}
	return (1);
}

/*
** comment
*/
