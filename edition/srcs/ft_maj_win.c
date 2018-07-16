/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_maj_win.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/02 18:50:00 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/09 15:27:3 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_edition.h"
#include <time.h>

static int		ft_move_arr(int tmp, t_navig *n)
{
	char	*ret;
	int		x;
	int		y;

	if (!(ret = tgetstr("le", NULL)))
		return (0);
	while (tmp > 0)
	{
		ft_recup_pos(&x, &y);
		if (tmp < 10)
		{
			if (!(ft_move_to_xy(0, y)))
				return (0);
			break ;
		}
		else if (x == 0)
		{
			if (!(ft_move_to_xy(n->x_size - 1, y - 1)))
				return (0);
		}
		else
			tputs(ret, 1, ft_putcharint);
		tmp--;
	}
	return (1);
}

static int		ft_goto_i_by_end(t_navig *n)
{
	int		j;
	int		i_bis;

	i_bis = n->i;
	j = ft_strlen(n->s);
	while (j > i_bis)
	{
		ft_x_change(n, MOVE_LEFT);//voir retour
		n->i++;
		j--;
	}
	if (!(ft_move_to_xy(n->x, n->y)))
		return (0);
	n->i = i_bis;
	return (1);
}

static int		ft_del_all(t_navig *n)
{
	char	*ret;

	ft_putstr(n->prompt);
	ft_recup_pos(&(n->x_start), &(n->y_start));
	ft_putstr(n->s);
	ft_recup_pos(&(n->x_len), &(n->y_len));
	ft_recup_pos(&(n->x), &(n->y));
	if (!(ft_goto_i_by_end(n)))
		return (0);
	return (1);
}

int				ft_maj_win(t_navig *n)
{
	char	*ret;
	int		tmp;
	int		x_stmp;
	int		y_stmp;
	int		y_calc;

	ft_get_size(&x_stmp, &y_stmp);
	if (x_stmp < n->x_size)
	{
		y_calc = (n->y - n->y_first) *
			(((n->x_size) / x_stmp) + 1) + (n->x / x_stmp);
		ft_get_size(&(n->x_size), &(n->y_size));
		ft_move_to_xy(0, n->y - y_calc);
	}
	else if (x_stmp > n->x_size)
	{
		ft_get_size(&(n->x_size), &(n->y_size));
		tmp = n->i + ft_strlen(n->prompt) + 1;
		ft_putchar(' ');
		ft_move_arr(tmp, n);
	}
	else
	{
		if (!(ft_get_size(&(n->x_size), &(n->y_size))))
			return (0);
		ft_recup_pos(&x_stmp, &y_stmp);
		tmp = (n->y - y_stmp);
		n->y_first -= tmp;
		n->y_start -= tmp;
		n->y_len -= tmp;
		n->y -= tmp;
		return (1);
	}
	if (!(ret = tgetstr("cd", NULL)))
		return (0);
	tputs(ret, 1, ft_putcharint);
	ft_recup_pos(&tmp, &(n->y_first));
	if (!(ft_del_all(n)))
		return (0);
	return (1);
}

/*
** fonction qui recup la taille de la fenetre
** on se remet au debut a voir avec le y_first
** et on del et reafiche la line
** maj de x/y size, len...
** si fenetre trop petite message d'erreur
**
** envoie du char * du prompt
*/