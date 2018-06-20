/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fork.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <bpajot@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/29 10:59:08 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/19 09:41:43 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "return_value.h"

int		ft_fork(char *path, char **tab, char **env)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
		ft_execve(path, tab, env);
	else if (pid > 0)
		wait(&status);
	return (WEXITSTATUS(status));
}
