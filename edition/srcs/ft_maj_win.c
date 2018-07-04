/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_maj_win.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/02 18:50:00 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/04 18:10:44 by kcabus      ###    #+. /#+    ###.fr     */
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
	while (j < i_bis)
	{
		ft_x_change(n, MOVE_LEFT);
		j--;
	}
	n->i = i_bis;
}

static int		ft_del_all(t_navig *n)
{
	char	*ret;

	ft_move_to_xy(0, n->y_first);
	if (!(ret = tgetstr("cd", NULL)))
		return (0);
	tputs(ret, 1, ft_putcharint);
	ft_putstr(n->prompt);
	ft_recup_pos(&(n->x_start), &(n->y_start));
	ft_putstr(n->s_aff);
	ft_recup_pos(&(n->x_len), &(n->y_len));
	ft_goto_i_by_end(n);
	return (1);
}

int				ft_maj_win(t_navig *n)
{
	int		new_x;
	int		new_y;

	ft_get_size(&(new_x), &(new_y));
//	if (new_x != n->x_size || new_y != n->y_size)
//	{
		n->x_size = new_x;
		n->y_size = new_y;
		ft_del_all(n);
		return (1);
//	}
//	return (0);
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