/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_edition.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/19 08:41:27 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/12 18:45:21 by kcabus      ###    #+. /#+    ###.fr     */
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
{
	ft_maj_win(&g_nav);
}

char			*ft_lance_edit(char *prompt, t_navig *n)
{
	char		buf[5];
	char		*tmp;

	ft_recup_pos(&(n->x_start), &(n->y_first));
	ft_putstr(prompt);
	ft_init_nav(n, prompt);
	ft_move_to_xy(n->x_start, n->y_start);
	while (1)//peut etre passer a une variable pour stop le while
	{
		if (signal(SIGWINCH, traite_signal) == SIG_ERR)
			perror("signal");
		ft_bzero(buf, 5);
		read(0, buf, 4);
		if (KEY_CODE_DIR)
		{
			if (ft_key_move(n, buf))
				ft_move_to_xy(n->x, n->y);
		}
		else if (KEY_CODE_DEL)
		{
			if (ft_del_char(n))
				ft_move_to_xy(n->x, n->y);
		}
		else if (buf[0] == 10)
		{
		//	printf("\n\n%s\n\n", n->s);
			ft_move_to_xy(n->x_len, n->y_len);
			ft_putstr("\n");
			if (n->s && (tmp = ft_whitespace(n->s)))
			{
				free(tmp);
				ft_add_hist(n->s);
			}
			return (n->s);
		}
		else if (KEY_CODE_ALT)
		{
			ft_key_alt(n, buf);
		}
		else if (IS_PRINTABLE)
		{
			if (ft_new_char(n, buf))
				ft_move_to_xy(n->x, n->y);
		}
	}
	return (NULL);
}

char				*ft_edition(char *prompt)
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
	if (!(str = ft_lance_edit(prompt, &g_nav)))
		return (NULL);
	ft_default_edit(t);
	return (str);
}

/*
**	printf("\n\n<|%d| - |%d| - |%d| - |%d| - |%d|>\n\n", buf[0], buf[1], buf[2], buf[3], buf[4]);
*/

/*
** int tcgetattr(int fd, struct termios *termios_p);
** int tcsetattr(int fd, int optional_actions,
**					const struct termios *termios_p);
** penser a close a la fin du programme
*/
