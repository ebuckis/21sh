/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   redir.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/23 13:32:47 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/26 19:14:09 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/exec.h"

static int		ft_redir_in(char *path, char **redirec, int i)
{
	int		fd;

	if (!ft_strcmp(redirec[i], "<"))
	{
		fd = open(path, O_RDONLY);
		dprintf(2, "< fd : %d\n", fd);
		dup2(fd, STDIN_FILENO);
	}
	else
	{
		ft_putendl("redirection parse error");
		return (-1);
	}
	return (fd);
}

static int		ft_redir_close(char **redirec, int i)
{
	int		fd;

	if (!ft_strcmp(redirec[i], ">&-") || !ft_strcmp(redirec[i], "1>&-"))
	{
		fd = 1;
		dprintf(2, ">&- fd : %d\n", fd);
		close(fd);
	}
	else if ((fd = ft_atoi(redirec[i])) >= 0 && ft_strstr(redirec[i], ">&-"))
	{
		dprintf(2, "n>&- fd : %d\n", fd);
		close(fd);
	}
	else
	{
		ft_putendl("redirection parse error");
		return (-1);
	}
	return (fd);
}

static int		ft_redir_out(char *path, char **redirec, int i)
{
	int		n;
	int		fd;
	char	*p;

	if (!ft_strcmp(redirec[i], ">"))
	{
		fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		dprintf(2, "> fd : %d\n", fd);
		dup2(fd, STDOUT_FILENO);
	}
	else if (!ft_strcmp(redirec[i], ">>"))
	{
		fd = open(path, O_WRONLY | O_CREAT | O_APPEND, 0644);
		dprintf(2, ">> fd : %d\n", fd);
		dup2(fd, STDOUT_FILENO);
	}
	else if (!ft_strcmp(redirec[i], ">&") || !ft_strcmp(redirec[i], "&>"))
	{
		fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		dprintf(2, "&> fd : %d\n", fd);
		dup2(fd, STDOUT_FILENO);
		dup2(fd, STDERR_FILENO);
	}
	else if ((n = ft_atoi(redirec[i])) >= 0 &&
			(p = ft_strchr(redirec[i], '>'))
			&& !p[1])
	{
		fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		dprintf(2, "n> fd : %d\n", fd);
		dup2(fd, n);
	}
	else
	{
		ft_putendl("redirection parse error");
		return (-1);
	}
	return (fd);
}

static void		ft_redir2(char **commande, char **redirec,
		int nb_redirec, char **env)
{
	int		i;
	int		fd;
	char	*pwd;
	char	*path;
	pid_t	pid;

	i = -1;
	fd = -1;
	while (redirec[++i])
	{
		if (ft_strchr(redirec[i * 2], '-'))
			fd = ft_redir_close(redirec, i);
		else
		{
			pwd = ft_getpwd(env, 0);
			pwd = ft_strjoin(pwd, "/");
			path = ft_strjoin(pwd, redirec[i + 1]);
			dprintf(2, "path : %s\n", path);
			if (ft_strchr(redirec[i], '>'))
				fd = ft_redir_out(path, redirec, i);
			else if (ft_strchr(redirec[i], '<'))
				fd = ft_redir_in(path, redirec, i);
			i++;
		}
	}
}

void			ft_redir(char **commande, char **redirec, char **env,
		int nb_redirec)
{
	if (nb_redirec)
		ft_redir2(commande, redirec, nb_redirec, env);
}
