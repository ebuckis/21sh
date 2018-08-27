/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_redir_out.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/27 11:53:11 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/27 11:55:45 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "exec.h"

int		ft_redir_out(t_parse *p, int *i, char **env)
{
	int		n;
	int		m;
	int		fd;
	char	*path;
	char	*pt;

	if (!ft_strcmp(p->arg[*i], ">"))
	{
		path = get_path_redir(p, i, env);
		if ((fd = open(path, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) >= 0)
		{
			dprintf(2, "> fd : %d\n", fd);
			dup2(fd, STDOUT_FILENO);
		}
	}
	else if (!ft_strcmp(p->arg[*i], ">>"))
	{
		path = get_path_redir(p, i, env);
		if ((fd = open(path, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) >= 0)
		{
			dprintf(2, ">> fd : %d\n", fd);
			dup2(fd, STDOUT_FILENO);
		}
	}
	else if (!ft_strcmp(p->arg[*i], ">&"))
	{
		path = get_path_redir(p, i, env);
		if ((fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) >= 0)
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
		if ((fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) >= 0)
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
