/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_bin.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <bpajot@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/01 14:24:58 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/26 16:32:59 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/exec.h"

static char	**ft_path(char **env)
{
	int		i;
	char	*path;
	char	**tab_bin;

	i = -1;
	while (env[++i])
	{
		if ((path = ft_strstr(env[i], "PATH=")))
		{
			path += 5;
			tab_bin = ft_strsplit(path, ':');
			return (tab_bin);
		}
	}
	return (NULL);
}

char		*check_bin3(char *bin, int warning)
{
	struct stat buf;
	int			ret;

	if ((ret = stat(bin, &buf)) == 0)
		return (bin);
	else
	{
		if (warning)
			ft_printf("21sh: no such file or directory: %s\n", bin);
	}
	return (NULL);
}

char		*check_bin2(char *tab0, char **env)
{
	char		*tmp;
	char		**tab_path;
	int			i;
	char		*bin;

	bin = tab0;
	tab_path = ft_path(env);
	i = -1;
	while (tab_path && tab_path[++i])
	{
		tmp = ft_strjoin(tab_path[i], "/");
		bin = ft_strjoin(tmp, tab0);
		ft_memdel((void**)&tmp);
		if (check_bin3(bin, 0))
		{
			ft_free_tab(tab_path);
			return (bin);
		}
		ft_memdel((void**)&bin);
	}
	ft_printf("21sh: command not found: %s\n", tab0);
	ft_free_tab(tab_path);
	return (NULL);
}

char		*check_bin(char **tab_pipe_i, char **env)
{
	if (tab_pipe_i[0][0] == '/' || (tab_pipe_i[0][0] == '.' &&
		tab_pipe_i[0][1] == '/'))
		return (check_bin3(tab_pipe_i[0], 1));
	else
		return (check_bin2(tab_pipe_i[0], env));
}
