/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_copy_paste.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/24 08:27:26 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/24 15:04:09 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_edition.h"

int		ft_cutstr_home(t_navig *n, char **copy, int nb)
{
	char	buf[5];
	int		i;

	ft_bzero(buf, 5);
	buf[0] = 127;
	if (n->i != 0)
	{
		ft_strdel(copy);//voir si null fonctionne
		i = n->i;
		if (!(*copy = ft_strnew(n->i)))
			return (0);
		*copy = ft_strncpy(*copy, n->s, n->i);
		if (nb == 1)
		{
			while (n->i)
				ft_key_code(n, buf);
		}
	}
	else
	{
		if (!ft_ring_the_bell())
			return (0);
	}
	dprintf(2, "**copy : |%s|**\n", *copy);
	return (1);
}

int		ft_cutstr_end(t_navig *n, char **copy, int nb)
{
	char	buf[5];
	int		i;

	ft_bzero(buf, 5);
	buf[0] = 127;
	if (n->i != ft_strlen(n->s))
	{
		ft_strdel(copy);
		i = n->i;
		if (!(*copy = ft_strnew(ft_strlen(n->s) - n->i)))
			return (0);
		while (n->s[i])
		{
			(*copy)[i - n->i] = n->s[i];
			i++;
		}
		if (nb == 1)
		{
			i = n->i;
			ft_move_to_xy(n->x_len, n->y_len);
			n->x = n->x_len;// transformer en une fonction
			n->y = n->y_len;
			n->i = ft_strlen(n->s);
			while (n->i != i)
				ft_key_code(n, buf);
		}
	}
	else
	{
		if (!ft_ring_the_bell())
			return (0);
	}
	return (1);
}

static int		ft_small_verif(t_navig *n, char *copy)
{
	int		np;
	int		ns;
	int		nc;

	np = (n->prompt) ? ft_strlen(n->prompt) : 0;
	ns = (n->s) ? ft_strlen(n->s) : 0;
	nc = (copy) ? ft_strlen(copy) : 0;
	dprintf(2, "np = %d,ns = %d, nc = %d,n->y_size = %d, n->x_size = %d\n", np, ns, np, n->y_size, n->x_size);
	dprintf(2, "total %d || %d size\n", np + ns + nc, n->y_size * n->x_size);
	if (np + ns + nc >= n->y_size * n->x_size)
		return (0);
	else
		return (1);
}

int		ft_paste(t_navig *n, char *copy)
{
	char	buf[5];
	int		i;

	i = 0;
	ft_bzero(buf, 5);
	if (copy && ft_small_verif(n, copy))
	{
		while (copy[i])
		{
			buf[0] = copy[i];
			ft_key_code(n, buf);
			i++;
		}
	}
	else
	{
		if (!ft_ring_the_bell())
			return (0);
	}
	return (1);
}

int		ft_copy_paste(t_navig *n, char *buf)
{
	static char	*copy = NULL;

	if (KEY_CTRL_U)
		ft_cutstr_home(n, &copy, 1);
	else if (KEY_CTRL_K)
		ft_cutstr_end(n, &copy, 1);
	else if (KEY_CTRL_E)
		ft_cutstr_home(n, &copy, 0);
	else if (KEY_CTRL_W)
		ft_cutstr_end(n, &copy, 0);
	else if (KEY_CTRL_T)
		ft_paste(n, copy);
	return (1);
}
