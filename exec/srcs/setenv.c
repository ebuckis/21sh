/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   setenv.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <bpajot@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/05 16:51:13 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/26 17:27:37 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/exec.h"

int			display_env(char **env)
{
	int		i;

	i = -1;
	while (env[++i])
		ft_putendl(env[i]);
	return (0);
}

int			ft_setenv2(char **arg, char ***env)
{
	char	**env2;
	char	*tmp;
	char	**tmp2;

	env2 = (char**)malloc(sizeof(char*) * 2);
	tmp = ft_strjoin(arg[1], "=");
	env2[0] = ft_strjoin(tmp, arg[2]);
	ft_memdel((void**)&tmp);
	env2[1] = NULL;
	tmp2 = ft_mix_env(*env, env2);
	ft_free_tab(*env);
	ft_free_tab(env2);
	*env = tmp2;
	return (0);
}

char		**ft_mix_env(char **env, char **env2)
{
	char	**arg;
	int		size_tab;
	int		i;
	int		j;
	int		k;

	size_tab = ft_tab_size(env, NULL) + ft_tab_size(env2, env);
	arg = (char**)malloc(sizeof(char*) * (size_tab + 1));
	i = 0;
	j = -1;
	while (env[++j])
	{
		if (!(ft_doublon(env[j], env2, -1)))
			arg[i++] = ft_strdup(env[j]);
	}
	j = i;
	k = i;
	while (env2[k - j])
	{
		if (!ft_doublon(env2[k - j], env2, k - j))
			arg[i++] = ft_strdup(env2[k - j]);
		k++;
	}
	arg[i] = NULL;
	return (arg);
}

int			ft_setenv(char **arg, char ***env)
{
	int		i;
	int		ret;

	ret = 1;
	if (!arg[1])
		ret = display_env(*env);
	else if (arg[2] && arg[3])
		ft_putendl("setenv: Too many arguments.");
	else if (!ft_isalpha(arg[1][0]))
		ft_putendl("setenv: Variable must begin with a letter.");
	else
	{
		i = -1;
		while (++i < (int)ft_strlen(arg[1]))
		{
			if (!ft_isalnum(arg[1][i]))
			{
				ft_putstr("setenv: Variable must contain alphanumeric ");
				ft_putendl("characters.");
				return (ret);
			}
		}
		ret = ft_setenv2(arg, env);
	}
	return (ret);
}
