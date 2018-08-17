/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   manage_signal.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/25 17:29:56 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/16 18:18:38 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/exec.h"

/*
** ft_signal_ctrl_c ignore le Ctrl-C pour le 21sh mais pas pour ces fils
** a faire, si edition en cours, return string NULL et p->ret = 1
*/

static void		ft_signal_ctrl_c(int s)
{
	(void)s;
	ft_putendl("");
	//ft_putstr("21sh $> ");
}

/*
** ft_signal_stop ignore le Ctrl-Z pour le 21sh mais pas pour ces fils
*/

static void		ft_signal_stop(int s)
{
	(void)s;
	ft_putendl("");
	//ft_putstr("21sh $> ");
}

void			manage_signal(void)
{
	setlocale(LC_ALL, "");
	ft_printf("%C kcabus\n%C bpajot\n", L'©', L'©');
	signal(SIGINT, ft_signal_ctrl_c);
	signal(SIGTSTP, ft_signal_stop);
	signal(SIGCONT, SIG_IGN);
}
