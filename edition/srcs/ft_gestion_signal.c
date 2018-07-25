/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_gestion_signal.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/25 12:57:00 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/25 14:19:02 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_edition.h"

void		ft_signal_size(int s)
{
	(void)s;
	dprintf(2, "on est sur un resize: |%d|\n", s);
	ft_maj_win(&g_nav);
}

void		ft_signal_stop(int s)
{
	t_navig		*n;
	char		str[2];

	(void)s;
	n = &g_nav;
	str[0] = n->t.c_cc[VSUSP];
	str[1] = '\0';
	dprintf(2, "on est sur un stop: |%d| string = %s\n", s, n->s);
	n->t = ft_default_edit(n->t);
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, str);
}

void		ft_signal_cont(int s)
{
	t_navig		*n;

	(void)s;
	n = &g_nav;
	dprintf(2, "on est sur un cont: |%d| string = %s\n", s, n->s);
	ft_init_term(&(g_nav.t));
	ft_maj_win(&g_nav);
}
