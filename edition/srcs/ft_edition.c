/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_edition.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/19 08:41:27 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/28 16:47:08 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_edition.h"

int				ft_putcharint(int c)
{
	write(1, &c, 1);
	return (1);
}


int		ft_voir_touche()
{
	char	buf[5];
	char	*res;
	t_navig	nav;

	ft_init_nav(&nav);
	res = tgetstr("cm", NULL);// permet de faire bouger le curseur
	tputs(tgoto(res, nav.x_start, nav.y_start), 1, ft_putcharint);
	while (1)
	{
		res = tgetstr("cm", NULL);
		ft_bzero(buf, 5);
		read(0, buf, 4);
		if (KEY_CODE_DIR)
		{
			if (ft_key_move(&nav, buf))
				tputs(tgoto(res, nav.x, nav.y), 1, ft_putcharint);
		}
		else if (KEY_CODE_DEL)
		{
			if (ft_del_char(&nav))
			tputs(tgoto(res, nav.x, nav.y), 1, ft_putcharint);
		}
		else if (buf[0] == 10)//entree
			return (1);
		else//definir une regle des caractere imprimables
		{
			if (ft_new_char(&nav, buf))
				tputs(tgoto(res, nav.x, nav.y), 1, ft_putcharint);
		}
	}
	return (0);
}
//		printf("<|%d| - |%d| - |%d| - |%d| - |%d|>", buf[0], buf[1], buf[2], buf[3], buf[4]);

int					ft_edition(void)
{
	struct termios	t;
	char			*name;

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
	ft_voir_touche();
	//ft_lecture();
	ft_default_edit(t);
	return (1);
}

/*
** int tcgetattr(int fd, struct termios *termios_p);
** int tcsetattr(int fd, int optional_actions,
**					const struct termios *termios_p);
*/
