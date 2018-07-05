/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fork.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <bpajot@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/29 10:59:08 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/05 15:15:58 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "pipes.h"

void		ft_fork_pipe(char ***tab, char **env, int nb_pipe)
{
	pid_t	pid;
	pid_t	pid2;
	int		status;
	int		pipeline[2];
	int		i;

	pid = fork();
	if (pid == 0)
	{
		i = 0;
		while(nb_pipe-- > 0)
		{
			pipe(pipeline);
			pid2 = fork();
			if (pid2 < 0)
			{
				close(pipeline[0]);
				close(pipeline[1]);
				ft_putendl("error");
			}
			else if (pid2 == 0) //child
			{
				dup2(pipeline[1], STDOUT_FILENO);
				close(pipeline[0]);
				ft_execve(tab[i][0], tab[i], env);
			}
			else if (pid2 > 0)
			{
				dup2(pipeline[0], STDIN_FILENO);
				close(pipeline[1]);
				wait(&status);
			}
			i++;
		}
		ft_execve(tab[i][0], tab[i], env);
	}
	else if (pid > 0)
	{
		wait(&status);
		ft_printf("return_value_final = %d\n", WEXITSTATUS(status));
	}
}
