/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_builtin.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <bpajot@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/01 18:20:01 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/24 15:13:41 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/exec.h"

int		check_builtin(char **tab_pipe_i)
{
	if (ft_strequ(tab_pipe_i[0], "echo") || ft_strequ(tab_pipe_i[0], "cd") ||
		ft_strequ(tab_pipe_i[0], "setenv") || ft_strequ(tab_pipe_i[0],
		"unsetenv") || ft_strequ(tab_pipe_i[0], "env") ||
		ft_strequ(tab_pipe_i[0], "exit"))
		return (1);
	else
		return (0);
}

void	run_builtin(t_parse *p, char **tab_pipe_i, char ***p_env)
{
	if (ft_strequ(tab_pipe_i[0], "echo"))
		ft_echo(tab_pipe_i);
	else if (ft_strequ(tab_pipe_i[0], "cd"))
		ft_cd(tab_pipe_i, p_env);
	else if (ft_strequ(tab_pipe_i[0], "setenv"))
		ft_setenv(tab_pipe_i, p_env);
	else if (ft_strequ(tab_pipe_i[0], "unsetenv"))
		ft_unsetenv(tab_pipe_i, p_env);
	else if (ft_strequ(tab_pipe_i[0], "env"))
		ft_env(p, tab_pipe_i, *p_env);
	else if (ft_strequ(tab_pipe_i[0], "exit"))
	// fait rien si entre pipe, si entre ';' gerer dans le main
		;
}
