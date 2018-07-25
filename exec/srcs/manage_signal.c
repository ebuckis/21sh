/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   manage_signal.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/25 17:29:56 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/25 18:27:48 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/exec.h"

static void		ft_signal_ctrl_c(int s)
{
	(void)s;
	dprintf(2, "\nCtrl-C received\n");
}

void		manage_signal(void)
{
		signal(SIGINT, ft_signal_ctrl_c); // ignorer Ctrl-C
		//signal(SIGINT, SIG_IGN); // ignorer Ctrl-C
		signal(SIGTSTP, ft_signal_stop);
		//signal(SIGTSTP, SIG_IGN);
}
