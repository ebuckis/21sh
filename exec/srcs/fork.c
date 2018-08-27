/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fork.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/29 10:59:08 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/27 12:17:09 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/exec.h"

static int		ft_fork_pipe(t_parse *p, int *tab_pipe, char ***p_env, int i)
{
	int		pid;
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
		ft_execve(p, tab_pipe[i], p_env);
	}
	else if (pid > 0)
	{
		dup2(pipeline[0], STDIN_FILENO);
		close(pipeline[1]);
		return (pid);
	}
	return (0);
}

void			ft_ret_display(t_parse *p, pid_t pid, int status)
{
	static pid_t	prev_pid = 0;

	if (WIFEXITED(status))
	{
		p->ret = WEXITSTATUS(status);
		if (p->ret)
			dprintf(2, "\e[31mreturn_value_final = %d\n\e[39m", p->ret);
		else
			dprintf(2, "\e[32mreturn_value_final = %d\n\e[39m", p->ret);
	}
	if (WIFSIGNALED(status))
	{
		p->ret = WTERMSIG(status) + 128;
		//ft retour signal
		dprintf(2, "\e[31mvalue_termsig_signal = %d\n\e[39m",
				WTERMSIG(status));
	}
	if (WIFSTOPPED(status))
	{
		p->child_pid = pid;
		dprintf(2, "prev_pid = %d   p->child_pid = %d\n",
				prev_pid, p->child_pid);
		if (prev_pid && prev_pid != p->child_pid)
		{
			kill(prev_pid, 2);
			prev_pid = p->child_pid;
		}
		else if (!prev_pid)
			prev_pid = p->child_pid;
		dprintf(2, "prev_pid = %d   p->child_pid = %d\n", prev_pid,
				p->child_pid);
		p->ret = WSTOPSIG(status) + 128;
		dprintf(2, "i\e[31mvalue_stop_signal = %d\n\e[39m",
				WSTOPSIG(status));
	}
}

void			ft_fork_shell(t_parse *p, int *tab_pipe, char ***p_env,
		int nb_pipe)
{
	pid_t			pid;
	pid_t			pid2;
	int				status;
	int				i;
	int				j;
	int				*pid_tab;

	pid = fork();
	if (pid == 0)
	{
		i = -1;
		if ((pid_tab = (int*)malloc(sizeof(int) * (nb_pipe + 2))))
		{
			pid_tab[nb_pipe + 1] = 0;
			j = nb_pipe;
			i = 0;
			while (j-- > 0)
			{
				pid_tab[i] = ft_fork_pipe(p, tab_pipe, p_env, i);
				i++;
			}
			pid2 = fork();
			if (pid2 == 0)
				ft_execve(p, tab_pipe[nb_pipe], p_env);
			else if (pid2 > 0)
			{
				waitpid(pid2, &status, WUNTRACED);
				j = nb_pipe;
				while (--j >= 0)
				{
					if ((ft_strequ(p->arg[tab_pipe[j]], "yes")) ||
						(ft_strequ(p->arg[tab_pipe[j]], "top")))
						kill(pid_tab[j], 9);
					waitpid(pid_tab[j], NULL, WUNTRACED);
				}
				exit(status);
			}
		}
		else
			exit(1);
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, WUNTRACED);
		ft_ret_display(p, pid, status);
	}
}
