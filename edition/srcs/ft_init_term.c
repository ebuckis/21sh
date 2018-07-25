/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init_term.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/25 13:56:51 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/25 13:57:37 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_edition.h"

int			ft_init_term(struct termios *t)
{
	char		*name;

	if (!(name = getenv("TERM")))
		return (0);
	if (tgetent(NULL, name) < 1)
		return (0);
	if (tcgetattr(0, t))
		return (0);
	t->c_lflag = t->c_lflag & ~(ICANON);
	t->c_lflag = t->c_lflag & ~(ECHO);
	t->c_cc[VMIN] = 1;
	t->c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, t) == -1)
		return (0);
	return (1);
}
