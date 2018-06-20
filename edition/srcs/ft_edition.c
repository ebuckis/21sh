/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_edition.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/19 08:41:27 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/19 18:26:40 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_edition.h"

int				ft_putcharint(int c)
{
	write(1, &c, 1);
	return (1);
}

void				ft_lecture(void)
{
}

int					ft_voir_touche(void)
{
	char	buf[5];
	char	*res;
	char	pos[10];
	int x;
	int y;

	char *str = "\033[6n";

	ft_bzero(pos, 10);
	printf("%s", str);
	read(0, pos, 10);
	y = (int)pos[2];
	x = (int)pos[3];
	printf("%d - %d - %d - %d - %d - %d - %d - %d - %d - %d\n", pos[0], pos[1], pos[2], pos[3], pos[4], pos[5], pos[6], pos[7], pos[8], pos[9]);
//	scanf("\033[%d;%dR", &y, &x);
	res = tgetstr("cm", NULL);
	tputs(tgoto(res, x, y), 1, ft_putcharint);
	while (1)
	{
		res = tgetstr("cm", NULL);
		ft_bzero(buf, 5);
		read(0, buf, 4);
		if (KEY_CODE_DIR)
		{
			if (KEY_CODE_UP)
				y--;
			else if (KEY_CODE_DOWN)
				y++;
			else if (KEY_CODE_LEFT)
				x--;
			else if (KEY_CODE_RIGHT)
				x++;
			else if (KEY_CODE_END)
				x++;
			else if (KEY_CODE_HOME)
			{
				y--;
			}
			tputs(tgoto(res, x, y), 1, ft_putcharint);
		}
		else if (buf[0] == 4)
		{
			printf("Ctlr+d, on quitte !\n");
			return (0);
		}
		else
		{
			ft_putchar(buf[0]);
			x++;
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
