/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_edition.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/19 08:41:27 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/09 12:11:18 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_edition.h"

t_navig		nav;

int				ft_putcharint(int c)
{
	write(1, &c, 1);
	return (1);
}
void			traite_signal(int s)
{
	ft_maj_win(&nav);
}

char			*ft_voir_touche(char *prompt)
{
	char		buf[5];

	ft_recup_pos(&(nav.x_start), &(nav.y_first));//recupere la position actuelle
	ft_putstr(prompt);
	ft_init_nav(&nav, prompt);
	ft_move_to_xy(nav.x_start, nav.y_start);
	while (1)//peut etre passer a une variable pour stop le while
	{
		if (signal(SIGWINCH, traite_signal) == SIG_ERR)
			perror("signal");
		ft_bzero(buf, 5);
		read(0, buf, 4);
	//	printf("\n\n<|%d| - |%d| - |%d| - |%d| - |%d|>\n\n", buf[0], buf[1], buf[2], buf[3], buf[4]);
		if (KEY_CODE_DIR)
		{
			if (ft_key_move(&nav, buf))
				ft_move_to_xy(nav.x, nav.y);
		}
		else if (KEY_CODE_DEL)
		{
			if (ft_del_char(&nav))
				ft_move_to_xy(nav.x, nav.y);
		}
		else if (buf[0] == 10)//entree
		{
			printf("\n\n%s\n\n", nav.s_aff);
			return (nav.s_aff);
		}
		else if (KEY_CODE_ALT_UP)
		{
			if (nav.y > nav.y_start && nav.x >= nav.x_start)
			{
				nav.y--;
				ft_move_to_xy(nav.x, nav.y);
			}
		}
		else if (KEY_CODE_ALT_DOWN)
		{
			if (nav.y < nav.y_len - 1 || (nav.y == nav.y_len - 1 && nav.x <= nav.x_len))//x_len a gerer
			{
				nav.y++;
				ft_move_to_xy(nav.x, nav.y);
			}
		}
		else if (IS_PRINTABLE)
		{
			if (ft_new_char(&nav, buf))
				ft_move_to_xy(nav.x, nav.y);
		}
	}
	return (NULL);
}
//		printf("<|%d| - |%d| - |%d| - |%d| - |%d|>", buf[0], buf[1], buf[2], buf[3], buf[4]);

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
	if (!(str = ft_voir_touche(prompt)))
		return (NULL);
	ft_default_edit(t);
	return (str);
}

/*
** int tcgetattr(int fd, struct termios *termios_p);
** int tcsetattr(int fd, int optional_actions,
**					const struct termios *termios_p);
*/
