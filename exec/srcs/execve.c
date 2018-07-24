/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   execve.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <bpajot@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/29 11:01:31 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/24 15:47:24 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/exec.h"

void		ft_execve(t_parse *p, char **tab_pipe_i, char ***p_env, int in_pipe)
{
	char			*path;
	char			**tab_com;
	struct stat		buf;
	int				ret;

	tab_com = manage_redir(tab_pipe_i, p_env);
	if (check_builtin(tab_com))
		run_builtin(p, tab_com, p_env, in_pipe);
	else
	{
		path = check_bin(tab_com, *p_env);
		if (path && !access(path, X_OK) && ((ret = stat(path, &buf)) == 0) &&
			(buf.st_mode & S_IFREG))
			execve(path, tab_com, *p_env);
		else if (path)
		{
		// pas les droits d'execution sur le fichier
			if (access(path, X_OK))
				ft_printf("21sh: permission denied: %s\n", tab_com[0]);
			else
				ft_printf("21sh: not a regular file: %s\n", tab_com[0]);
			exit(126);
		}
		else
		// le fichier n'existe pas
			exit(127);
	}
}
