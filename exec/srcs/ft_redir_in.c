/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_redir_in.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/27 11:55:19 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/27 11:56:49 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "exec.h"

int		ft_redir_in(t_parse *p, int *i, char **env)
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
