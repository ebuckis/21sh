/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tilde_dollar.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/14 12:03:04 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/14 15:15:57 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_parser.h"

static char		*ft_home(char **env)
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

static t_parse		*ft_tilde(t_parse *p, int i, char **env)
{
	char	*home;
	char	*tmp;

	home = ft_home(env);
	if (home)
	{
		tmp = ft_strjoin(home, &(p->arg[i][1]));
		ft_memdel((void**)&(p->arg[i]));
		p->arg[i] = ft_strdup(tmp);
		ft_memdel((void**)&tmp);
		ft_memdel((void**)&(p->arg_id[i]));
		p->arg_id[i] = ft_memalloc(ft_strlen(p->arg[i]) + 1);
		ft_bzero((void*)p->arg_id[i], ft_strlen(p->arg[i]) + 1);
		ft_memset((void*)p->arg_id[i], WORD, ft_strlen(p->arg[i]));
		ft_memdel((void**)&home);
	}
	return (p);
}

//static t_parse		*ft_dollar(t_parse *p, int i, char **env)

t_parse		*ft_tilde_dollar(t_parse *p, char **env)
{
	int		i;

	i = 0;
	if (p->arg)
	{
		while (p->arg[i])
		{
			if (p->arg[i][0] == '~' && p->arg_id[i][0] == WORD)
				ft_tilde(p, i, env);
			//if (ft_strchr(p->arg[i], '$')) 
			//	p = ft_dollar(p, i);
			i++;
		}
	}
	return (p);
}
