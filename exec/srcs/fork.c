/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fork.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/29 10:59:08 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/23 19:43:54 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/exec.h"

static int		*ft_fork_pipe(t_parse *p, int *tab_pipe, char ***p_env, int i)
{
	int		pid;
	int		pipeline[2];
	int		*pid_pipe;

	pipe(pipeline);
	dprintf(2, "pipe[0] = %d\npipe[1] = %d\n", pipeline[0], pipeline[1]);
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
		if ((pid_pipe = (int*)malloc(sizeof(int) * 3)))
		{
			pid_pipe[0] = pid;
			pid_pipe[1] = pipeline[0];
			pid_pipe[2] = pipeline[1];
		}
		return (pid_pipe);
	}
	return (NULL);
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
	int				buf;
	int				i;
	int				j;
	int				*pid_pipe;
	t_pid_pipe		**pp;

	pid = fork();
	if (pid == 0)
	{
		i = -1;
		pp = (t_pid_pipe**)malloc(sizeof(t_pid_pipe*) * (nb_pipe + 2));
		while (++i < nb_pipe + 1)
		{
			pp[i] = (t_pid_pipe*)malloc(sizeof(t_pid_pipe));
			dprintf(2, "pp[%d] = %p\n", i, pp[i]);
		}
		pp[nb_pipe + 1] = NULL;
		pp[0]->pipeline[0] = 0;
		pp[nb_pipe]->pid = pid;
		pp[nb_pipe]->pipeline[1] = 1;
		j = nb_pipe;
		i = 0;
		while (j-- > 0)
		{
			pid_pipe = ft_fork_pipe(p, tab_pipe, p_env, i);
			pp[i]->pid = pid_pipe[0];
			pp[i + 1]->pipeline[0] = pid_pipe[1];
			pp[i]->pipeline[1] = pid_pipe[2];
			i++;
		}
		j = -1;
		while (pp[++j])
			dprintf(2, "pp[%d]: pid=%d pipe[0]=%d pipe[1]=%d\n",
				j, pp[j]->pid, pp[j]->pipeline[0], pp[j]->pipeline[1]);
		pid2 = fork();
		if (pid2 == 0)
			ft_execve(p, tab_pipe[nb_pipe], p_env);
		else if (pid2 > 0)
		{
			waitpid(pid2, &status, WUNTRACED);
			j = nb_pipe;
			while (--j >= 0)
			{
				dprintf(2, "pp[%d]->pid = %d waiting\n", j, pp[j]->pid);
				if ((ft_strequ(p->arg[tab_pipe[j]], "yes")) ||
					(ft_strequ(p->arg[tab_pipe[j]], "top")))
					kill(pp[j]->pid, 9);
				waitpid(pp[j]->pid, NULL, WUNTRACED);
				dprintf(2, "pp[%d]->pid = %d finish\n", j, pp[j]->pid);
			}
			exit(status);
		}
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, WUNTRACED);
		ft_ret_display(p, pid, status);
	}
}
