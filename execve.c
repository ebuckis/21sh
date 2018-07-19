/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   execve.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <bpajot@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/29 11:01:31 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/19 16:09:38 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "21sh.h"

void		ft_execve(char **tab_pipe_i, char ***p_env)
{
	char *path;

	if (check_builtin(tab_pipe_i, p_env))
		return;
	else
		path = check_bin(tab_pipe_i, *p_env);
	if (path)
		execve(path, tab_pipe_i, *p_env);
}
