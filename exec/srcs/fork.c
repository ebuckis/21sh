/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fork.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/29 10:59:08 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/29 13:54:08 by kcabus      ###    #+. /#+    ###.fr     */
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

int				ft_ret_display(t_parse *p, pid_t pid, int status)
{
	static pid_t	prev_pid = 0;

	if (WIFEXITED(status))
		p->ret = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		p->ret = WTERMSIG(status) + 128;
	else if (WIFSTOPPED(status))
	{
		p->ret = WSTOPSIG(status) + 128;
		p->child_pid = pid;
		if (prev_pid && prev_pid != p->child_pid)
		{
			kill(prev_pid, 2);
			prev_pid = p->child_pid;
		}
		else if (!prev_pid)
			prev_pid = p->child_pid;
	}
	return (p->ret);
}

static void		ft_fork_shell3(t_parse *p, int *tab_pipe, int *pid_tab,
		int pid)
{
	int			i;
	int			status;

	waitpid(pid, &status, WUNTRACED);
	i = -1;
	while (pid_tab[++i])
		;
	while (--i >= 0)
	{
		if ((ft_strequ(p->arg[tab_pipe[i]], "yes")) ||
				(ft_strequ(p->arg[tab_pipe[i]], "top")))
			kill(pid_tab[i], 9);
		waitpid(pid_tab[i], NULL, WUNTRACED);
	}
	exit(ft_ret_display(p, pid, status));
}

static void		ft_fork_shell2(t_parse *p, int *tab_pipe, char ***p_env,
		int nb_pip)
{
	int			i;
	int			*pid_tab;
	pid_t		pid;
	int			status;

	i = -1;
	if ((pid_tab = (int*)malloc(sizeof(int) * (nb_pip + 1))))
	{
		pid_tab[nb_pip] = 0;
		i = nb_pip + 1;
		while (--i > 0)
			pid_tab[nb_pip - i] = ft_fork_pipe(p, tab_pipe, p_env, nb_pip - i);
		if (nb_pip)
		{
			pid = fork();
			if (pid == 0)
				ft_execve(p, tab_pipe[nb_pip], p_env);
			else if (pid > 0)
				ft_fork_shell3(p, tab_pipe, pid_tab, pid);
		}
		else
			ft_execve(p, tab_pipe[nb_pip], p_env);
	}
	else
		exit(1);
}

void			ft_fork_shell(t_parse *p, int *tab_pipe, char ***p_env,
		int nb_pipe)
{
	pid_t			pid;
	int				status;
	char			**tab_com;

	if (!nb_pipe && (ft_strequ(p->arg[tab_pipe[0]], "cd") ||
		(ft_strequ(p->arg[tab_pipe[0]], "setenv") ||
		ft_strequ(p->arg[tab_pipe[0]], "unsetenv"))))
	{
		tab_com = manage_redir(p, tab_pipe[0], p_env);
		run_builtin(p, tab_com, p_env, 0);
	}
	else
	{
		pid = fork();
		if (pid == 0)
			ft_fork_shell2(p, tab_pipe, p_env, nb_pipe);
		else if (pid > 0)
		{
			waitpid(pid, &status, WUNTRACED);
			ft_ret_display(p, pid, status);
		}
	}
}
