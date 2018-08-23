/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   redir.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/23 13:32:47 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/23 13:18:39 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/exec.h"

static char		*get_path_redir(t_parse *p, int *i, char **env)
{
	char	*pwd;
	char	*tmp;
	char	*path;

	pwd = ft_getpwd(env, 0);
	tmp = ft_strjoin(pwd, "/");
	(*i)++;
	path = ft_strjoin(tmp, p->arg[*i]);
	dprintf(2, "path : %s\n", path);
	ft_strdel(&pwd);
	ft_strdel(&tmp);
	return (path);
}

static int		ft_redir_in(t_parse *p, int *i, char **env)
{
	int		fd;
	int		n;
	char	*pt;
	char	*path;

	if (!ft_strcmp(p->arg[*i], "<"))
	{
		path = get_path_redir(p, i, env);
		if ((fd = open(path, O_RDONLY)) >= 0)
		{
			dprintf(2, "< fd : %d\n", fd);
			dup2(fd, STDIN_FILENO);
		}
	}
	else if ((n = ft_atoi(p->arg[*i])) >= 0 && (pt = ft_strchr(p->arg[*i], '<'))
		&& !pt[1])
	{
		path = get_path_redir(p, i, env);
		if ((fd = open(path, O_RDONLY)) >= 0)
		{
			dprintf(2, "n< fd : %d\n", fd);
			dup2(fd, n);
		}
	}
	else
	{
		ft_putendl("redirection parse error");
		return (-1);
	}
	if (fd < 0)
		ft_printf("21sh: %s: Permission denied\n", p->arg[*i]);
	if (path)
		ft_strdel(&path);
	return (fd);
}

static int		ft_redir_close(t_parse *p, int *i)
{
	int		fd;

	if (!ft_strcmp(p->arg[*i], ">&-") || !ft_strcmp(p->arg[*i], "1>&-"))
	{
		fd = 1;
		dprintf(2, ">&- fd : %d\n", fd);
		close(fd);
	}
	else if ((fd = ft_atoi(p->arg[*i])) >= 0 && ft_strstr(p->arg[*i], ">&-"))
	{
		dprintf(2, "n>&- fd : %d\n", fd);
		close(fd);
	}
	else
		ft_putendl("redirection parse error");
	return (fd);
}

static int		ft_redir_out(t_parse *p, int *i, char **env)
{
	int		n;
	int		m;
	int		fd;
	char	*path;
	char	*pt;

	if (!ft_strcmp(p->arg[*i], ">"))
	{
		path = get_path_redir(p, i, env);
		if ((fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644)) >= 0)
		{
			dprintf(2, "> fd : %d\n", fd);
			dup2(fd, STDOUT_FILENO);
		}
	}
	else if (!ft_strcmp(p->arg[*i], ">>"))
	{
		path = get_path_redir(p, i, env);
		if ((fd = open(path, O_WRONLY | O_CREAT | O_APPEND, 0644)) >= 0)
		{
			dprintf(2, ">> fd : %d\n", fd);
			dup2(fd, STDOUT_FILENO);
		}
	}
	else if (!ft_strcmp(p->arg[*i], ">&"))
	{
		path = get_path_redir(p, i, env);
		if ((fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644)) >= 0)
		{
			dprintf(2, "&> fd : %d\n", fd);
			dup2(fd, STDOUT_FILENO);
			dup2(fd, STDERR_FILENO);
		}
	}
	else if ((n = ft_atoi(p->arg[*i])) >= 0 && (pt = ft_strchr(p->arg[*i], '>'
			)) && !pt[1])
	{
		path = get_path_redir(p, i, env);
		if ((fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644)) >= 0)
		{
			dprintf(2, "n> fd : %d\n", fd);
			dup2(fd, n);
		}
	}
	else if ((n = ft_atoi(p->arg[*i])) >= 0 && (pt = ft_strstr(&(p->arg[*i][1])
		, ">&")) && pt[2] && (m = ft_atoi(&(pt[2]))) >=0)
	{
		dprintf(2, "n>&m : %d>&%d\n", n, m);
		dup2(m, n);
	}
	else if ((pt = ft_strstr(p->arg[*i], ">&")) && pt[2] &&
			(m = ft_atoi(&(pt[2]))) >=0)
	{
		dprintf(2, ">&m : >&%d\n", m);
		dup2(m, STDOUT_FILENO);
		dup2(m, STDERR_FILENO);
	}
	else
	{
		ft_putendl("redirection parse error");
		return (-1);
	}
	if (fd < 0)
		ft_printf("21sh: %s: Permission denied\n", p->arg[*i]);
	if (path)
		ft_strdel(&path);
	return (fd);
}

static int		ft_redir_heredoc(t_parse *p, int *i, char **env)
{
	char		*home;
	char		*tmp;
	char		*path;
	int			fd;

	(*i)++;
	home = ft_home(env);
	tmp = ft_strjoin(home, "/");
	path = ft_strjoin(tmp, ".heredoc");
	if ((fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644)) >= 0)
	{
		ft_putstr_fd(p->arg[*i], fd);
		close(fd);
		fd = open(path, O_RDONLY);
		dup2(fd, STDIN_FILENO);
	}
	ft_strdel(&home);
	ft_strdel(&tmp);
	ft_strdel(&path);
	return (fd);
}

void			ft_redir(t_parse *p, int *redir_lim, char **env,
		int nb_redirec)
{
	int		i;
	pid_t	pid;
	int		fd;

	fd = 0;
	if (nb_redirec)
	{
		i = redir_lim[1] - 1;
		while (p->arg[++i] && p->arg_id[i][0] < PIPE)
		{
			if (ft_strchr(p->arg[i], '-'))
				fd = ft_redir_close(p, &i);
			else if (ft_strchr(p->arg_id[i], HEREDOC))
				fd = ft_redir_heredoc(p, &i, env);
			else
			{
				if (ft_strchr(p->arg[i], '>'))
					fd = ft_redir_out(p, &i, env);
				else if (ft_strchr(p->arg[i], '<'))
					fd = ft_redir_in(p, &i, env);
			}
		}
	}
	if (fd < 0)
		exit(1);
}
