/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   manage_redir.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/11 16:43:01 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/12 15:45:13 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "redirec.h"

static char		*ft_getpwd(char **env)
{
	int		i;
	char	*pwd;

	i = -1;
	if (env)
	{
		while (env[++i])
		{
			if ((pwd = ft_strstr(env[i], "PWD=")) &&
					!ft_strstr(env[i], "OLDPWD="))
				return (ft_strdup(pwd + 4));
		}
	}
	return (NULL);
}

static void		ft_manage_redir2(char **redirec, int nb_redirec, char **env)
{
	int		i;
	int		fd;
	char	*pwd;
	char	*path;

	i = -1;
	fd = 0;
	while (++i < nb_redirec)
	{
		pwd = ft_getpwd(env);
		pwd = ft_strjoin(pwd, "/");
		path = ft_strjoin(pwd, redirec[i * 2 + 1]);
		ft_printf("path : %s\n", path);
		if (!ft_strcmp(redirec[i * 2], ">"))
		{
		// ajouter verifier droit lecture user et autres
			fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
			ft_printf("> fd : %d\n", fd);
			dup2(fd, STDOUT_FILENO);
		}
		if (!ft_strcmp(redirec[i * 2], ">>"))
		{
			fd = open(path, O_APPEND | O_WRONLY | O_CREAT | O_TRUNC, 0644);
			ft_printf(">> fd : %d\n", fd);
			dup2(fd, STDOUT_FILENO);
		}
	}
	redirec = NULL;
}

void		ft_manage_redir(char **commande, char **redirec, char **env,
		int nb_redirec)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		if (nb_redirec)
			ft_manage_redir2(redirec, nb_redirec, env);
		ft_execve(commande[0], commande, env);
	}
	else if (pid > 0)
	{
		wait(&status);
		ft_printf("return_value_final = %d\n", WEXITSTATUS(status));
	}
}
