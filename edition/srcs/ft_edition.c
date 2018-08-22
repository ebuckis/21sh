/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_edition.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/19 16:17:54 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/22 16:59:36 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_edition.h"

char		*ft_ctrl_s(t_navig *n)
{
	n->s = ft_strdup("exit");
	ft_push_enter(n);
	return (n->s);
}

static int	ft_whilesuite(t_navig *n, char *buf)
{
	if (KEY_CODE_DIR || KEY_CODE_DEL || KEY_CODE_ALT || IS_PRINTABLE)
	{
		if (!(ft_key_code(n, buf)))
			return (0);
	}
	else
		ft_copy_paste(n, buf, 0);
	return (1);
}

char		*ft_lance_edit(t_navig *n)
{
	char		buf[5];

	if (!(ft_move_to_xy(n->x_start, n->y_start)))
		return (NULL);
	while (1)
	{
		while (ft_verif_term_size(n) < 0)
			ft_maj_win(n);
		ft_bzero(buf, 5);
		read(0, buf, 4);
		//dprintf(2, "|%d|_|%d|_|%d|_|%d|\n", buf[0], buf[1], buf[2], buf[3]);
		if (buf[0] == 10 && !buf[1])
		{
			if (!(ft_push_enter(n)))
				return (NULL);
			break ;
		}
		else if (KEY_CTRL_D)
			return (ft_ctrl_s(n));
		else if (!ft_whilesuite(n, buf))
			return (NULL);
	}
	ft_strdel(&(n->s_save));
	return (n->s);
}

char		*ft_edition(char *prompt)
{
	char		*str;

	str = NULL;
	if (!(ft_init_term(&(g_nav.t))))
		return (NULL);
	if (!(ft_init_nav(&g_nav, prompt)))
		return (NULL);
	signal(SIGWINCH, ft_signal_size);
	str = ft_lance_edit(&g_nav);
	g_nav.t = ft_default_edit(g_nav.t);
	return (str);
}

/*
** int tcgetattr(int fd, struct termios *termios_p);
** int tcsetattr(int fd, int optional_actions,
**					const struct termios *termios_p);
** penser a close a la fin du programme
*/
