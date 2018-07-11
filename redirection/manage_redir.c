/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   manage_redir.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/11 16:43:01 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/11 16:48:30 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "redirec.h"

static void		ft_manage_redir2(char **redirec, int nb_redirec)
{
	int		fd;

	fd = 0;
	nb_redirec = 0;
	redirec = NULL;
//	dup2(fd, STDOUT_FILENO);
}

void		ft_manage_redir(char **commande, char **redirec, char **env,
		int nb_redirec)
{
	pid_t	pid;
	int		status;
	int		i;

	pid = fork();
	if (pid == 0)
	{
		i = 0;
		while (nb_redirec-- > 0)
		{
			ft_manage_redir2(redirec, nb_redirec);
			i++;
		}
		ft_execve(commande[0], commande, env);
	}
	else if (pid > 0)
	{
		wait(&status);
		ft_printf("return_value_final = %d\n", WEXITSTATUS(status));
	}
}
