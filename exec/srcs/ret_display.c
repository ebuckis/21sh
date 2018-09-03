/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ret_display.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/29 11:37:28 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/09/03 15:18:22 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "exec.h"

/*
** affichage des signaux qui interrompe un processus
*/

static void		ft_ret_display_signal2(int signal)
{
	if (signal == 8)
		ft_printf("Floating point exception: ");
	else if (signal == 9)
		ft_printf("Killed: ");
	else if (signal == 10)
		ft_printf("Bus error: ");
	else if (signal == 11)
		ft_printf("Segfault: ");
	else if (signal == 12)
		ft_printf("Bad system call: ");
	else if (signal == 13)
		ft_printf("Broken Pipe: ");
	else if (signal == 14)
		ft_printf("Alarm: ");
	else if (signal == 15)
		ft_printf("Terminated: ");
	else if (signal == 17 || signal == 18)
		ft_printf("Stopped: ");
}

/*
** affichage des signaux qui interrompe un processus
*/

static void		ft_ret_display_signal(pid_t pid, int status, int stop)
{
	int		signal;

	signal = (stop) ? WSTOPSIG(status) : WTERMSIG(status);
	if (signal > 0 && signal < 32)
	{
		ft_printf("pid: %d\t", pid);
		if (signal == 1)
			ft_printf("Hangup: ");
		else if (signal == 2)
			ft_printf("Interupt: ");
		else if (signal == 3)
			ft_printf("Quit: ");
		else if (signal == 4)
			ft_printf("Illegal instruction: ");
		else if (signal == 5)
			ft_printf("Trace trap: ");
		else if (signal == 6)
			ft_printf("Abort trap: ");
		else if (signal == 7)
			ft_printf("EMT trap: ");
		else
			ft_ret_display_signal2(signal);
		ft_printf("Signal = %d\n", signal);
	}
}

/*
** gestion des signaux de retour des processus pour les mettre dans p->ret
*/

int				ft_ret_display(t_parse *p, pid_t pid, int status)
{
	static pid_t	prev_pid = 0;

	if (WIFEXITED(status))
		p->ret = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		p->ret = WTERMSIG(status) + 128;
		ft_ret_display_signal(pid, status, 0);
	}
	else if (WIFSTOPPED(status))
	{
		p->ret = WSTOPSIG(status) + 128;
		ft_ret_display_signal(pid, status, 1);
		p->child_pid = pid;
		if (prev_pid && prev_pid != p->child_pid)
		{
			kill(prev_pid, 2);
			prev_pid = p->child_pid;
		}
		else if (!prev_pid)
			prev_pid = p->child_pid;
	}
	return (p->ret);
}
