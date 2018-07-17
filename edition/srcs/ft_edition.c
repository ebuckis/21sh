/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_edition.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/19 08:41:27 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/17 18:41:10 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_edition.h"

t_navig		g_nav;

int				ft_putcharint(int c)
{
	write(1, &c, 1);
	return (1);
}

static void		traite_signal(int s)
{//s a traiter
	(void)s;
	ft_maj_win(&g_nav);
}

char			*ft_lance_edit(char *prompt, t_navig *n)
{
	char		buf[5];

	if (!(ft_init_nav(n, prompt)))
		return (NULL);
	if (!(ft_move_to_xy(n->x_start, n->y_start)))
		return (NULL);
	while (1)
	{
		if (signal(SIGWINCH, traite_signal) == SIG_ERR)
			return (NULL);
		ft_bzero(buf, 5);
		read(0, buf, 4);
		if (KEY_CODE_DIR || KEY_CODE_DEL || KEY_CODE_ALT || IS_PRINTABLE)
		{
			if (!(ft_key_code(n, buf)))
				return (NULL);
		}
		else if (buf[0] == 10 && !buf[1])
		{
			if (!(ft_push_enter(n)))
				return (NULL);
			break ;
		}
	}
	return (n->s);
}

char			*ft_edition(char *prompt)
{
	struct termios	t;
	char			*name;
	char			*str;

	str = NULL;
	if (!(name = getenv("TERM")))
		return (0);
	if (tgetent(NULL, name) < 1)
		return (0);
	if (tcgetattr(0, &t))
		return (0);
	t.c_lflag = t.c_lflag & ~(ICANON);
	t.c_lflag = t.c_lflag & ~(ECHO);
	t.c_cc[VMIN] = 1;
	t.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &t) == -1)
		return (0);
	str = ft_lance_edit(prompt, &g_nav);
	dprintf(2, "str = ft_lance edit\n");
	ft_default_edit(t);
	dprintf(2, "return de str\n");
	return (str);
}

/*
** int tcgetattr(int fd, struct termios *termios_p);
** int tcsetattr(int fd, int optional_actions,
**					const struct termios *termios_p);
** penser a close a la fin du programme
*/
