/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fork.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <bpajot@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/29 10:59:08 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/05 17:37:41 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "pipes.h"

static void		ft_fork_pipe2(char ***tab, char **env, int i)
{
	pid_t	pid;
	int		pipeline[2];

	pipe(pipeline);
	pid = fork();
	if (pid < 0)
	{
		close(pipeline[0]);
		close(pipeline[1]);
		ft_putendl("error");
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
		wait(NULL);
	}
}

void			ft_fork_pipe(char ***tab, char **env, int nb_pipe)
{
	pid_t	pid;
	int		status;
	int		i;

	pid = fork();
	if (pid == 0)
	{
		i = 0;
		while (nb_pipe-- > 0)
		{
			ft_fork_pipe2(tab, env, i);
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
