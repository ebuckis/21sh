/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_builtin.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <bpajot@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/01 18:20:01 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/26 16:27:08 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/exec.h"

int		check_builtin(char **tab_pipe_i)
{
	if (ft_strequ(tab_pipe_i[0], "echo") || ft_strequ(tab_pipe_i[0], "cd") ||
		ft_strequ(tab_pipe_i[0], "setenv") || ft_strequ(tab_pipe_i[0],
		"unsetenv") || ft_strequ(tab_pipe_i[0], "env") ||
		ft_strequ(tab_pipe_i[0], "exit") || ft_strequ(tab_pipe_i[0], "fg"))
		return (1);
	else
		return (0);
}

void	run_builtin(t_parse *p, char **tab_pipe_i, char ***p_env, int in_pipe)
{
	if (ft_strequ(tab_pipe_i[0], "echo"))
		p->ret = ft_echo(tab_pipe_i);
	else if (ft_strequ(tab_pipe_i[0], "cd"))
		p->ret = ft_cd(tab_pipe_i, p_env);
	else if (ft_strequ(tab_pipe_i[0], "setenv"))
		p->ret = ft_setenv(tab_pipe_i, p_env);
	else if (ft_strequ(tab_pipe_i[0], "unsetenv"))
		p->ret = ft_unsetenv(tab_pipe_i, p_env);
	else if (ft_strequ(tab_pipe_i[0], "env"))
		p->ret = ft_env(p, tab_pipe_i, *p_env);
	else if (ft_strequ(tab_pipe_i[0], "fg"))
		p->ret = ft_fg(p);
	else if (ft_strequ(tab_pipe_i[0], "exit"))
		;
	if (in_pipe)
		exit(p->ret);
	else if (p->ret)
		dprintf(2, "\e[31mreturn_value_final = %d\n\e[39m", p->ret);
	else
		dprintf(2, "\e[32mreturn_value_final = %d\n\e[39m", p->ret);
}
