/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_key_move.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/22 15:58:05 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/11 19:11:05 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_edition.h"

static int		ft_maj_stuct_nav(t_navig *n, char *n)
{

}

int				ft_key_move(t_navig *n, char *buf)
{
	char	*str;

	if (KEY_CODE_UP)
	{
		str = ft_give_historique(1, NULL);
		if (str)
			ft_maj_stuct_nav(n, str);
	}
	else if (KEY_CODE_DOWN)
	{
		str = ft_give_historique(1, NULL);
		if (str)
			ft_maj_stuct_nav(n, str);
		else
			ft_maj_stuct_nav(n, s_save);
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
		n->x = n->x_start;
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