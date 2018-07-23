/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   execve.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <bpajot@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/29 11:01:31 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/23 14:11:22 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/exec.h"

void		ft_execve(char **tab_pipe_i, char ***p_env)
{
	char	*path;
	char	**tab_com;

	tab_com = manage_redir(tab_pipe_i, p_env);
	if (check_builtin(tab_com, p_env))
		exit(0);
	else
	{
		path = check_bin(tab_com, *p_env);
		if (path && !access(path, X_OK))
			execve(path, tab_com, *p_env);
		else if (path)
		// pas les droits d'execution sur le fichier
			exit(126);
		else
		// le fichier n'existe pas
			exit(127);
	}
}
