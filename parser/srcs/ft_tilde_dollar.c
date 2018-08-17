/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tilde_dollar.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/14 12:03:04 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/17 14:35:24 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_parser.h"

/*static char		*ft_home(char **env)
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
}*/

static char		*ft_strjoin_free(char *line1, char *line2, int i, int j)
{
	char *tmp;

	tmp = ft_strjoin(line1, line2);
	if (i)
		ft_memdel((void**)&line1);
	if (j)
		ft_memdel((void**)&line2);
	return (tmp);
}

/*static char		*ft_getenv_value(char **env, char *key)
{
	int		i;
	char	*p;
	char	*tmp;

	i = -1;
	if (env)
	{
		while (env[++i])
		{
			tmp = ft_strjoin_free(key, "=", 1, 0);
			if ((p = ft_strnstr(env[i], tmp, ft_strlen(tmp))))
			{
				ft_memdel((void**)&tmp);
				return (ft_strdup(p + ft_strlen(key + 1)));
			}
			ft_memdel((void**)&tmp);
		}
	}
	return (NULL);
}*/

static t_parse		*ft_tilde(t_parse *p, int i, char **env)
{
	char	*home;
	char	*tmp;

	home = getenv("HOME");
	if (home)
	{
		tmp = ft_strjoin_free(home, &(p->arg[i][1]), 0, 0);
		ft_memdel((void**)&(p->arg[i]));
		p->arg[i] = ft_strdup(tmp);
		ft_memdel((void**)&tmp);
		ft_memdel((void**)&(p->arg_id[i]));
		p->arg_id[i] = ft_memalloc(ft_strlen(p->arg[i]) + 1);
		ft_bzero((void*)p->arg_id[i], ft_strlen(p->arg[i]) + 1);
		ft_memset((void*)p->arg_id[i], WORD, ft_strlen(p->arg[i]));
	}
	return (p);
}

static t_parse		*ft_dollar(t_parse *p, int i, int j, char **env)
{
	char	*var;
	char	*key;
	char	*tmp;
	char	*arg;
	char	*p1;
	char	*p2;

	p1 = ft_strchr(&(p->arg[i][j]), '{');
	p2 = ft_strchr(&(p->arg[i][j]), '}');
	var = (p1 && p2 && p2 > p1) ? ft_strsub(p1, 1, p2 - p1 - 1) : 
		ft_strdup(&(p->arg[i][j + 1]));
	key = (ft_strequ(var, "?")) ? ft_itoa(p->ret) : ft_strdup(getenv(var));
	dprintf(2, "var = %s\n", var);
	dprintf(2, "key = %s\n", key);
	if (j)
		tmp = ft_strjoin(ft_strsub(p->arg[i], 0, j), key);
	else
		tmp = (key) ? ft_strdup(key) : ft_strdup("");
	arg = (p1 && p2 && p2 > p1) ? ft_strjoin(tmp, &(p->arg[i][j + 1]) +
		ft_strlen(var) + 2) : ft_strdup(tmp);
	ft_memdel((void**)&(p->arg[i]));
	ft_memdel((void**)&tmp);
	dprintf(2, "arg = %s\n", arg);
	ft_memdel((void**)&(p->arg[i]));
	p->arg[i] = ft_strdup(arg);
	ft_memdel((void**)&arg);
	ft_memdel((void**)&(p->arg_id[i]));
	p->arg_id[i] = ft_memalloc(ft_strlen(p->arg[i]) + 1);
	ft_bzero((void*)p->arg_id[i], ft_strlen(p->arg[i]) + 1);
	ft_memset((void*)p->arg_id[i], WORD, ft_strlen(p->arg[i]));
	ft_memdel((void**)&var);
	ft_memdel((void**)&key);
	return (p);
}

t_parse		*ft_tilde_dollar(t_parse *p, char **env)
{
	int		i;
	int		j;

	i = -1;
	if (p->arg)
	{
		while (p->arg[++i])
		{
			if (p->arg[i][0] == '~' && p->arg_id[i][0] == WORD)
				ft_tilde(p, i, env);
			if (ft_strchr(p->arg[i], '$'))
			{
				j = -1;
				while (p->arg[i][++j])
				{
					if (p->arg[i][j] == '$' && p->arg[i][j + 1] &&
						(p->arg_id[i][j] == WORD || p->arg_id[i][j] ==
						DOUBLE_QUOTE))
						p = ft_dollar(p, i, j, env);
				}
			}
		}
	}
	return (p);
}
