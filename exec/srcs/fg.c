/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fg.c                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/26 13:26:26 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/26 16:30:03 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/exec.h"

int		ft_fg(t_parse *p)
{
	int		status;

	if (p->child_pid)
	{
		kill(p->child_pid, 19);
		waitpid(p->child_pid, &status, WUNTRACED);
		if (WIFEXITED(status))
		{
			p->ret = WEXITSTATUS(status);
			if (p->ret)
				dprintf(2, "\e[31mreturn_value_final = %d\n\e[39m", p->ret);
			else
				dprintf(2, "\e[32mreturn_value_final = %d\n\e[39m", p->ret);
			p->child_pid = 0;
		}
		if (WIFSIGNALED(status))
		{
			p->ret = WTERMSIG(status) + 128;
			dprintf(2, "\e[31mvalue_termsig_signal = %d\n\e[39m",
					WTERMSIG(status));
			p->child_pid = 0;
		}
		if (WIFSTOPPED(status))
		{
			p->ret = WSTOPSIG(status) + 128;
			dprintf(2, "\e[31mvalue_stop_signal = %d\n\e[39m",
					WSTOPSIG(status));
		}
		return (p->ret);
	}
	else
		return (1);
}
