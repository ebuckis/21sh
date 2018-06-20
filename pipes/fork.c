/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fork.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <bpajot@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/29 10:59:08 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/20 14:55:51 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "pipes.h"

int		ft_fork_pipe(char ***tab, char **env)
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
