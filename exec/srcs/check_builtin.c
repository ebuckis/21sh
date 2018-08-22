/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_builtin.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <bpajot@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/01 18:20:01 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/22 13:36:28 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/exec.h"

int		check_builtin(char **tab_com)
{
	if (ft_strequ(tab_com[0], "echo") || ft_strequ(tab_com[0], "cd") ||
		ft_strequ(tab_com[0], "setenv") || ft_strequ(tab_com[0], "unsetenv") ||
		ft_strequ(tab_com[0], "env") || ft_strequ(tab_com[0], "exit") ||
		ft_strequ(tab_com[0], "fg"))
		return (1);
	else
		return (0);
}

void	run_builtin(t_parse *p, char **tab_com, char ***p_env,
		int tab_pipe_i)
{
	if (ft_strequ(tab_com[0], "echo"))
		p->ret = ft_echo(tab_com);
	else if (ft_strequ(tab_com[0], "cd"))
		p->ret = ft_cd(tab_com, p_env);
	else if (ft_strequ(tab_com[0], "setenv"))
		p->ret = ft_setenv(tab_com, p_env);
	else if (ft_strequ(tab_com[0], "unsetenv"))
		p->ret = ft_unsetenv(tab_com, p_env);
	else if (ft_strequ(tab_com[0], "env"))
		p->ret = ft_env(p, tab_com, *p_env, tab_pipe_i);
	else if (ft_strequ(tab_com[0], "fg"))
		p->ret = ft_fg(p);
	else if (ft_strequ(tab_com[0], "exit"))
		;
	exit(p->ret);
}
