/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   echo.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <bpajot@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/01 18:32:44 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/17 13:33:40 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "redirec.h"

int		ft_echo(char **tab)
{
	int		i;
	int		n;

	n = (tab[1] && ft_strequ(tab[1], "-n")) ? 1 : 0;
	i = (n) ? 1 : 0;
	while (tab[++i])
	{
		ft_putstr(tab[i]);
		if (tab[i + 1])
			ft_putchar(' ');
		else if (!n)
			ft_putchar('\n');
	}
	return (1);
}
