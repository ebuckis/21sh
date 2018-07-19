/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   getenv.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <bpajot@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/31 09:21:41 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/19 15:56:30 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "21sh.h"

char		**ft_getenv(int argc, char *argv[], char *env[])
{
	int		i;
	char	**myenv;

	argc = 1;
	argv = NULL;
	i = -1;
	if (!env)
		return (NULL);
	while (env[++i])
		;
	myenv = (char**)malloc(sizeof(char*) * (i + 1));
	i = -1;
	while (env[++i])
		myenv[i] = ft_strdup(env[i]);
	myenv[i] = NULL;
	i = -1;
	return (myenv);
}

char		*ft_home(char **env)
{
	int		i;
	char	*home;

	i = -1;
	if (env)
	{
		while (env[++i])
		{
			if ((home = ft_strstr(env[i], "HOME=")))
				return (ft_strdup(home + 5));
		}
	}
	return (NULL);
}

char		*ft_getpwd(char **env, int old)
{
	int		i;
	char	*pwd;

	i = -1;
	if (env)
	{
		while (env[++i])
		{
			if (old == 0)
			{
				if ((pwd = ft_strstr(env[i], "PWD=")) &&
					!ft_strstr(env[i], "OLDPWD="))
					return (ft_strdup(pwd + 4));
			}
			else
			{
				if ((pwd = ft_strstr(env[i], "OLDPWD=")))
					return (ft_strdup(pwd + 7));
			}
		}
	}
	return (NULL);
}

void		ft_setpwd(char **env, int old, char *pwd)
{
	int		i;

	i = -1;
	if (env)
	{
		while (env[++i])
		{
			if (old == 0)
			{
				if (ft_strstr(env[i], "PWD=") && !ft_strstr(env[i], "OLDPWD="))
				{
					ft_memdel((void **)&env[i]);
					env[i] = ft_strjoin("PWD=", pwd);
				}
			}
			else
			{
				if (ft_strstr(env[i], "OLDPWD="))
				{
					ft_memdel((void **)&env[i]);
					env[i] = ft_strjoin("OLDPWD=", pwd);
				}
			}
		}
	}
}
