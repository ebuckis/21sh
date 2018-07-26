/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   manage_signal.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/25 17:29:56 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/26 15:28:15 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/exec.h"

/*
// ft_signal_ctrl_c ignore le Ctrl-C pour le 21sh mais pas pour ces fils
// a faire, si edition en cours, return string NULL et p->ret = 1
*/
static void		ft_signal_ctrl_c(int s)
{
	(void)s;
	dprintf(2, "\nCtrl-C received\n");
}

/*
// ft_signal_stop ignore le Ctrl-Z pour le 21sh mais pas pour ces fils
*/
static void		ft_signal_stop(int s)
{
	//	t_navig		*n;
	//	char		str[2];
	//static pid_t	prev_pid = 0;
	//t_parse			*p;

	(void)s;
	dprintf(2, "\nCtrl-Z received\n");
	ft_putendl("");
	//p = ft_save_struct(NULL);
	//	n = &g_nav;
	//	str[0] = n->t.c_cc[VSUSP];
	//	str[1] = '\0';
	//	dprintf(2, "on est sur un stop: |%d| string = %s\n", s, n->s);
	//	n->t = ft_default_edit(n->t);
	//	signal(SIGTSTP, SIG_DFL);
	//	ioctl(0, TIOCSTI, str);
}

static void		ft_signal_cont(int s)
{
	t_navig		*n;

	(void)s;
	//	n = &g_nav;
	//	dprintf(2, "on est sur un cont: |%d| string = %s\n", s, n->s);
	//	ft_init_term(&(g_nav.t));
	//	ft_maj_win(&g_nav);
}

void		manage_signal(void)
{
	signal(SIGINT, ft_signal_ctrl_c);
	//signal(SIGINT, SIG_IGN); // ignorer Ctrl-C
	signal(SIGTSTP, ft_signal_stop);
	//signal(SIGTSTP, SIG_IGN);
	signal(SIGCONT, ft_signal_cont);
}
