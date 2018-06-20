/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fork.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <bpajot@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/29 10:59:08 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/20 16:38:07 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "pipes.h"

int		ft_fork_pipe(char ***tab, char **env, int nb_pipe)
{
	pid_t	pid;
	int		status;
	int		pipeline[2];
	int		i;

	i = 0;
	while(nb_pipe-- > 0)
	{
		pipe(pipeline);
		ft_putendl("pipe");
		pid = fork();
		if (pid < 0)
		{
			close(pipeline[0]);
			close(pipeline[1]);
			ft_putendl("error");
			break;
		}
		else if (pid == 0)
		{
			dup2(pipeline[1], STDOUT_FILENO);
			close(pipeline[0]);
			ft_execve(tab[i][0], tab[i], env);
		}
		else if (pid > 0)
		{
			dup2(pipeline[0], STDIN_FILENO);
			close(pipeline[1]);
			wait(&status);
		}
		i++;
	}
	pid = fork();
	if (pid == 0)
		ft_execve(tab[i][0], tab[i], env);
	else if (pid > 0)
		wait(&status);
	return (WEXITSTATUS(status));
}
