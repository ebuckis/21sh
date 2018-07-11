/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fork.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <bpajot@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/29 10:59:08 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/11 15:02:47 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "pipes.h"
#include <fcntl.h>

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
// dup de la sortie standard du fils sur le cote ecriture du pipe
// fermetrure du cote lecture du pipe
	{
		dup2(pipeline[1], STDOUT_FILENO);
		close(pipeline[0]);
		ft_execve(tab[i][0], tab[i], env);
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

void			ft_fork_pipe(char ***tab, char **env, int nb_pipe)
{
	pid_t	pid;
	int		status;
	int		i;

// fork principal du shell
	pid = fork();
	if (pid == 0)
	{
		i = 0;
		while (nb_pipe-- > 0)
		{
// forks mutliples pour chaque commande pipe
			ft_fork_pipe2(tab, env, i);
			i++;
		}
// execve de la derniere commande
		ft_execve(tab[i][0], tab[i], env);
	}
	else if (pid > 0)
	{
// wait de la derniere commande puis recuperation de la valeur de retour
		wait(&status);
		ft_printf("return_value_final = %d\n", WEXITSTATUS(status));
	}
}
