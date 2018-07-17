/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   setenv.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <bpajot@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/05 16:51:13 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/17 13:35:18 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "redirec.h"

void		display_env(char **env)
{
	int		i;

	i = -1;
	while (env[++i])
		ft_putendl(env[i]);
}

void		ft_setenv2(char **tab, char ***env)
{
	char	**env2;
	char	*tmp;
	char	**tmp2;

	env2 = (char**)malloc(sizeof(char*) * 2);
	tmp = ft_strjoin(tab[1], "=");
	env2[0] = ft_strjoin(tmp, tab[2]);
	ft_memdel((void**)&tmp);
	env2[1] = NULL;
	tmp2 = ft_mix_env(*env, env2);
	ft_free_tab(*env);
	ft_free_tab(env2);
	*env = tmp2;
}

void		ft_setenv(char **tab, char ***env)
{
	int		i;

	if (!tab[1])
		display_env(*env);
	else if (tab[2] && tab[3])
		ft_putendl("setenv: Too many arguments.");
	else if (!ft_isalpha(tab[1][0]))
		ft_putendl("setenv: Variable must begin with a letter.");
	else
	{
		i = -1;
		while (++i < (int)ft_strlen(tab[1]))
		{
			if (!ft_isalnum(tab[1][i]))
			{
				ft_putstr("setenv: Variable must contain alphanumeric ");
				ft_putendl("characters.");
				return ;
			}
		}
		ft_setenv2(tab, env);
	}
}
