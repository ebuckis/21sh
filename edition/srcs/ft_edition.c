/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_edition.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/19 08:41:27 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/21 18:19:26 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_edition.h"

int				ft_putcharint(int c)
{
	write(1, &c, 1);
	return (1);
}

void				ft_recup_pos(int *x, int *y)
{
	char	pos[20];
	char	*str;
	int		i;

	i = 0;
	str = "\033[6n";
	ft_bzero(pos, 20);
	ft_printf("%s", str);
	read(0, pos, 20);
	*y = ft_atoi(pos + 2);
	while (pos[i] && pos[i] != 59)
		i++;
	*x = ft_atoi(pos + i);
	printf("|%d| - |%d|\n", *x, *y);
}

void				ft_lecture(void)
{
}

int					ft_get_size(int *x, int *y)
{
	struct winsize	w;

	if (ioctl(0, TIOCGWINSZ, &w) == -1)
		return (0);
	*y = w.ws_row;
	*x = w.ws_col;
	return (1);
}

void				ft_x_change(t_navig *n, int i)// i == 1 -> ++ else --
{
	if (i == 1)
	{
		if (n->x < n->x_size)//a modif
			n->x++;
		else if (n->y < n->y_size)// a modifier
		{
			n->x = 0;
			n->y++;
		}
	}
	else
	{
		if (n->x > n->x_start)//a modif
			n->x--;
		else if (n->y > n->y_start)// a modifier
		{
			n->x = n->x_size;
			n->y--;
		}
	}
}

int					ft_key_move(t_navig *n, char *buf)
{
	if (KEY_CODE_UP)
		n->y--;
	else if (KEY_CODE_DOWN)
		n->y++;
	else if (KEY_CODE_LEFT)
		ft_x_change(n, 0);
	else if (KEY_CODE_RIGHT)
		ft_x_change(n, 1);
	else if (KEY_CODE_END)
	{
		n->x = n->x_size;
		n->y = n->y_size;
	}
	else if (KEY_CODE_HOME)
	{
		n->x = n->x_start;
		n->y = n->y_start;
	}
	else
		return (0);
	return (1);
}

int					ft_voir_touche(void)
{
	char	buf[5];
	char	*res;
	t_navig	nav;

	ft_get_size(&(nav.x_size), &(nav.y_size));
	printf("<%d><%d>\n", nav.x_size, nav.y_size);
	ft_recup_pos(&(nav.x_start), &(nav.y_start));//recupere la position actuelle
	nav.x = nav.x_start;
	nav.y = nav.y_start;
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
		else
		{
//			printf("<|%d| - |%d| - |%d| - |%d| - |%d|>", buf[0], buf[1], buf[2], buf[3], buf[4]);
			if (buf[0] == 10)
				return (1);
			else if (buf[0] == 4)
			{
				printf("Ctlr+d, on quitte !\n");
				return (0);
			}
			else
			{
				ft_x_change(n, 1);
				ft_putchar(buf[0]);
			}
		}
	}
	return (0);
}

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
