/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_builtin.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <bpajot@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/01 18:20:01 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/17 13:40:18 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "redirec.h"

int		check_builtin(char **tab, char ***env)
{
	if (ft_strequ(tab[0], "echo"))
		return (ft_echo(tab));
	else if (ft_strequ(tab[0], "cd"))
		return (ft_cd(tab, *env));
	else if (ft_strequ(tab[0], "setenv"))
	{
		ft_setenv(tab, env);
		return (1);
	}
	else if (ft_strequ(tab[0], "unsetenv"))
	{
		ft_unsetenv(tab, env);
		return (1);
	}
	else if (ft_strequ(tab[0], "env"))
	{
		ft_env(tab, *env);
		return (1);
	}
	else if (ft_strequ(tab[0], "exit"))
		ft_exit(tab, *env, 1);
	return (0);
}
