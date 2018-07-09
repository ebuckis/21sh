/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_maj_win.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/02 18:50:00 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/05 17:07:13 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_edition.h"

static void		ft_goto_i_by_end(t_navig *n)
{
	int		j;
	int		i_bis;

	i_bis = n->i;
	j = ft_strlen(n->s_aff);
	while (j > i_bis)
	{
		ft_x_change(n, MOVE_LEFT);
		n->i++;
		j--;
	}
	ft_move_to_xy(n->x, n->y);
	n->i = i_bis;
}

static int		ft_del_all(t_navig *n)
{
	char	*ret;

	ft_putstr(n->prompt);
	ft_recup_pos(&(n->x_start), &(n->y_start));
	ft_putstr(n->s_aff);
	ft_recup_pos(&(n->x_len), &(n->y_len));
	ft_recup_pos(&(n->x), &(n->y));
	ft_goto_i_by_end(n);
	return (1);
}

int				ft_maj_win(t_navig *n)
{
	char	*ret;
	int		y_tmp;

	ft_get_size(&(n->x_size), &(n->y_size));
	y_tmp = n->y_first;
	if (!(ret = tgetstr("cd", NULL)))
		return (0);
	while (y_tmp < n->y_size)
	{
		ft_move_to_xy(0, y_tmp);
		tputs(ret, 1, ft_putcharint);
		y_tmp++;
	}
	if (!(ret = tgetstr("cl", NULL)))
		return (0);
	tputs(ret, 1, ft_putcharint);
	n->y_first = 0;
	ft_del_all(n);
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