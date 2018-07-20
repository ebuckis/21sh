/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   execve.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <bpajot@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/29 11:01:31 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/19 18:07:23 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "21sh.h"

void		ft_execve(char **tab_pipe_i, char ***p_env)
{
	char	*path;

	if (check_builtin(tab_pipe_i, p_env))
		exit(0);
	else
	{
		path = check_bin(tab_pipe_i, *p_env);
		if (path && !access(path, X_OK))
			execve(path, tab_pipe_i, *p_env);
		else if (path)
		// pas les droits d'execution sur le fichier
			exit(126);
		else
		// le fichier n'existe pas
			exit(127);
	}
}
