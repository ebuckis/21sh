/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_builtin.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <bpajot@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/01 18:20:01 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/19 16:02:34 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "21sh.h"

int		check_builtin(char **tab_pipe_i, char ***p_env)
{
	if (ft_strequ(tab_pipe_i[0], "echo"))
		return (ft_echo(tab_pipe_i));
	else if (ft_strequ(tab_pipe_i[0], "cd"))
		return (ft_cd(tab_pipe_i, *p_env));
	else if (ft_strequ(tab_pipe_i[0], "setenv"))
	{
		ft_setenv(tab_pipe_i, p_env);
		return (1);
	}
	else if (ft_strequ(tab_pipe_i[0], "unsetenv"))
	{
		ft_unsetenv(tab_pipe_i, p_env);
		return (1);
	}
	else if (ft_strequ(tab_pipe_i[0], "env"))
	{
		ft_env(tab_pipe_i, *p_env);
		return (1);
	}
	//else if (ft_strequ(tab[0], "exit"))
	//	ft_exit(tab, *env, 1);
	return (0);
}
