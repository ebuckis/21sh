/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   execve.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/29 11:01:31 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/09/03 10:32:20 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "exec.h"

static void		ft_execve_warning(char *path, char **tab_com)
{
	if (access(path, X_OK))
		ft_printf("21sh: permission denied: %s\n", tab_com[0]);
	else
		ft_printf("21sh: not a regular file: %s\n", tab_com[0]);
	ft_free_tab(&tab_com);
	exit(126);
}

void			ft_execve(t_parse *p, int tab_pipe_i, char ***p_env)
{
	char			*path;
	char			**tab_com;
	struct stat		buf;
	int				ret;

	if (!p->arg[tab_pipe_i][0])
		exit(0);
	tab_com = manage_redir(p, tab_pipe_i, p_env);
	if (check_builtin(tab_com))
		run_builtin_fork(p, tab_com, p_env, tab_pipe_i);
	else
	{
		path = check_bin(tab_com, *p_env);
		if (path && !access(path, X_OK) && ((ret = stat(path, &buf)) == 0) &&
				(buf.st_mode & S_IFREG))
			execve(path, tab_com, *p_env);
		else if (path)
			ft_execve_warning(path, tab_com);
		else
		{
			ft_free_tab(&tab_com);
			exit(127);
		}
	}
	ft_free_tab(&tab_com);
}
