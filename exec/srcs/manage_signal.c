/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   manage_signal.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/25 17:29:56 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/26 16:59:15 by bpajot      ###    #+. /#+    ###.fr     */
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
	ft_putstr("prompt $>");
}

/*
** ft_signal_stop ignore le Ctrl-Z pour le 21sh mais pas pour ces fils
*/

static void		ft_signal_stop(int s)
{
	(void)s;
	ft_putendl("");
	ft_putstr("prompt $>");
}

void			manage_signal(void)
{
	signal(SIGINT, ft_signal_ctrl_c);
	signal(SIGTSTP, ft_signal_stop);
	signal(SIGCONT, SIG_IGN);
}
