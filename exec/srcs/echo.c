/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   echo.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/01 18:32:44 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/30 12:20:11 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "exec.h"

int		ft_echo(char **arg)
{
	int		i;
	int		n;

	n = (arg[1] && ft_strequ(arg[1], "-n")) ? 1 : 0;
	i = (n) ? 1 : 0;
	if (!arg[i + 1])
		ft_putchar('\n');
	while (arg[++i])
	{
		ft_putstr(arg[i]);
		if (arg[i + 1])
			ft_putchar(' ');
		else if (!n)
			ft_putchar('\n');
	}
	return (0);
}
