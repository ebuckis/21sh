/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fork.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <bpajot@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/29 10:59:08 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/17 13:49:45 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "redirec.h"

void		ft_fork(char *path, char **tab, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		tab[0] = ft_strdup(path);
		ft_execve(tab, env);
	}
	else if (pid > 0)
		wait(NULL);
	ft_memdel((void**)&path);
}
