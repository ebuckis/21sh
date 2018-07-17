/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   exit.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <bpajot@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/05 16:17:23 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/17 13:34:00 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "redirec.h"

void		ft_exit(char **tab, char **env, int i)
{
	int		ret;

	ft_putendl("exit");
	if (i)
	{
		ret = (tab[1]) ? ft_atoi(tab[1]) : 0;
		ft_free_tab(tab);
		ft_free_tab(env);
		exit(ret);
	}
	ft_free_tab(env);
	exit(0);
}
