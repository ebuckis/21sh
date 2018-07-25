/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fork.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <bpajot@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/29 10:59:08 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/25 12:06:09 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/exec.h"

static void		ft_fork_pipe(t_parse *p, char ***tab_pipe, char ***p_env, int i)
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
		// dup de la sortie standard du fils sur le cote ecriture du pipe
		// fermetrure du cote lecture du pipe
	{
		dup2(pipeline[1], STDOUT_FILENO);
		close(pipeline[0]);
		ft_execve(p, tab_pipe[i], p_env, 1);
	}
	else if (pid > 0)
	{
		// dup de l'entree standard du pere sur le cote lecture du pipe
		// fermetrure du cote ecriture du pipe
		dup2(pipeline[0], STDIN_FILENO);
		close(pipeline[1]);
		// pas d'attente du fils, les commandes fonctionnne en parallele pour ne pas
		// avoir de probleme avec la buffer size du pipe, le processus pere vide le
		// pipe des qu'il y a du texte a lire
		//	wait(NULL);
	}
}

void			ft_fork_shell(t_parse *p, char ***tab_pipe, char ***p_env,
		int nb_pipe)
{
	pid_t	pid;
	int		status;
	int		i;

	if (!nb_pipe && check_builtin(tab_pipe[0]))
		run_builtin(p, tab_pipe[0], p_env, 0);
	else
	{
		// fork principal du shell
		pid = fork();
		if (pid == 0)
		{
			i = 0;
			while (nb_pipe-- > 0)
			{
				// forks mutliples pour chaque commande pipe
				ft_fork_pipe(p, tab_pipe, p_env, i);
				i++;
			}
			// execve de la derniere commande
			ft_execve(p, tab_pipe[i], p_env, 1);
		}
		else if (pid > 0)
		{
			// wait de la derniere commande puis recuperation de la valeur de retour
			wait(&status);
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
				dprintf(2, "\e[31mvalue_termsig_signal = %d\n\e[39m",
					WTERMSIG(status));
			}
			if (WIFSTOPPED(status))
				dprintf(2, "value_stop_signal = %d\n", WSTOPSIG(status));
		}
	}
}
