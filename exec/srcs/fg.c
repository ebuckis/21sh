/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fg.c                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/26 13:26:26 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/27 16:30:08 by bpajot      ###    #+. /#+    ###.fr     */
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
			p->ret = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			p->ret = WTERMSIG(status) + 128;
		else if (WIFSTOPPED(status))
			p->ret = WSTOPSIG(status) + 128;
		return (p->ret);
	}
	else
		return (1);
}
