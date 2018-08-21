/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   env.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/04 14:50:45 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/21 16:05:41 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "redirec.h"

static int	ft_doublon(char *line, char **tab, int j)
{
	int		i;
	char	*p;
	char	*p2;
	char	*p3;
	char	*p4;

	i = j;
	p2 = ft_strchr(line, '=');
	while (tab[++i])
	{
		if ((p = ft_strchr(tab[i], '=')))
		{
			p3 = ft_strsub(tab[i], 0, p - tab[i]);
			p4 = ft_strsub(line, 0, p2 - line);
			if (ft_strequ(p3, p4))
			{
				ft_memdel((void**)&p3);
				ft_memdel((void**)&p4);
				return (1);
			}
			ft_memdel((void**)&p3);
			ft_memdel((void**)&p4);
		}
	}
	return (0);
}

static int	ft_tab_size(char **tab, char **tab_ref)
{
	int		i;
	int		doublon;

	i = -1;
	doublon = 0;
	while (tab[++i])
		doublon += (tab_ref && (ft_doublon(tab[i], tab_ref, -1) ||
			ft_doublon(tab[i], tab, i))) ? 1 : 0;
	return (i - doublon);
}

char		**ft_mix_env(char **env, char **env2)
{
	char	**tab;
	int		size_tab;
	int		i;
	int		j;
	int		k;

	size_tab = ft_tab_size(env, NULL) + ft_tab_size(env2, env);
	tab = (char**)malloc(sizeof(char*) * (size_tab + 1));
	i = 0;
	j = -1;
	while (env[++j])
	{
		if (!(ft_doublon(env[j], env2, -1)))
			tab[i++] = ft_strdup(env[j]);
	}
	j = i;
	k = i;
	while (env2[k - j])
	{
		if (!ft_doublon(env2[k - j], env2, k - j))
			tab[i++] = ft_strdup(env2[k - j]);
		k++;
	}
	tab[i] = NULL;
	return (tab);
}

static void	ft_env2(char **tab, char **env, int i)
{
	char	*bin;

	if (tab[i])
	{
		if (!check_builtin(&tab[i], &env))
		{
			if ((bin = check_bin(&tab[i], env)))
				ft_fork(bin, &tab[i], env);
		}
	}
	else
		display_env(env);
}

void		ft_env(char **tab, char **env)
{
	int		i;
	int		option_i;
	char	**env2;
	char	**env3;

	i = -1;
	if (!tab[1])
		display_env(env);
	else
	{
		option_i = (ft_strequ(tab[1], "-i")) ? 1 : 0;
		i = option_i;
		while (tab[++i] && ft_strchr(tab[i], '='))
			;
		env2 = (char**)malloc(sizeof(char*) * i);
		i = option_i;
		while (tab[++i] && ft_strchr(tab[i], '='))
			env2[i - option_i - 1] = ft_strdup(tab[i]);
		env2[i - option_i - 1] = NULL;
		env3 = (option_i) ? env2 : ft_mix_env(env, env2);
		ft_env2(tab, env3, i);
		if (!option_i)
			ft_memdel((void**)&env3);
		ft_free_tab(&env2);
	}
}
