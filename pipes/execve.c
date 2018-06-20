/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   execve.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <bpajot@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/29 11:01:31 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/19 11:14:47 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "pipes.h"

int		ft_execve(char *path, char *tab[], char *env[])
{
	int		i;

	i = 0;
	ft_printf("bin : \"%s\"\n", path);
	while (tab[++i])
		ft_printf("argv[%d] : \"%s\"\n", i, tab[i]);
	execve(path, tab, env);
	return (0);
}
