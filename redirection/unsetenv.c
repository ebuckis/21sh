/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   unsetenv.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/06 15:06:04 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/21 16:06:58 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "redirec.h"

static int	ft_doublon(char *line, char **tab)
{
	int		i;
	char	*p;
	char	*tmp;

	i = -1;
	if (tab)
	{
		while (tab[++i])
		{
			p = ft_strchr(tab[i], '=');
			if (p && ft_strequ((tmp = ft_strsub(tab[i], 0, p - tab[i])), line))
			{
				ft_memdel((void**)&tmp);
				return (1);
			}
			if (tmp)
				ft_memdel((void**)&tmp);
		}
	}
	return (0);
}

static int	ft_doublon2(char *line, char **tab)
{
	int		i;
	char	*p;
	char	*tmp;

	i = 0;
	if (tab)
	{
		while (tab[++i])
		{
			p = ft_strchr(line, '=');
			if (p && ft_strequ((tmp = ft_strsub(line, 0, p - line)), tab[i]))
			{
				ft_memdel((void**)&tmp);
				return (1);
			}
			if (tmp)
				ft_memdel((void**)&tmp);
		}
	}
	return (0);
}

static int	ft_tab_size(char **tab)
{
	int		i;

	i = -1;
	if (tab)
	{
		while (tab[++i])
			;
		return (i);
	}
	return (0);
}

static char	**ft_unsetenv2(char **tab, char **env, int nb_double)
{
	char	**env2;
	int		i;
	int		j;

	env2 = (char**)malloc(sizeof(char*) *
		(ft_tab_size(env) - nb_double + 1));
	i = 0;
	j = i;
	while (env[i])
	{
		if (ft_doublon2(env[i], tab))
			i++;
		else
		{
			env2[j] = ft_strdup(env[i]);
			j++;
			i++;
		}
	}
	env2[j] = NULL;
	return (env2);
}

void		ft_unsetenv(char **tab, char ***env)
{
	int		i;
	int		nb_double;
	char	**tmp;

	nb_double = 0;
	if (!tab[1])
		ft_putendl("unsetenv: Too few arguments.");
	else
	{
		i = 0;
		while (tab[++i])
		{
			if (ft_doublon(tab[i], *env))
				nb_double++;
		}
		if (nb_double)
		{
			tmp = ft_unsetenv2(tab, *env, nb_double);
			ft_free_tab(env);
			*env = tmp;
		}
	}
}
