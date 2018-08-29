/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   manage_redir.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/23 13:32:33 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/29 17:54:14 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "exec.h"

static void		display(char **tabl)
{
	int		i;

	i = -1;
	while (tabl[++i])
		dprintf(2, "%s\n", tabl[i]);
}

static char		**create_commande(t_parse *p, int begin, int sep)
{
	int		i;
	char	**commande;

	commande = (char**)malloc(sizeof(char*) * (sep - begin + 1));
	i = -1;
	while (++i < sep - begin)
		commande[i] = ft_strdup(p->arg[i + begin]);
	commande[i] = NULL;
	return (commande);
}

static int		manage_redir2(t_parse *p, int *i, int *redir_lim,
		int *nb_redir)
{
	int		begin;

	begin = *i + 1;
	while (p->arg[++(*i)] && p->arg_id[*i][0] < PIPE)
	{
		if (ft_strchr(p->arg_id[*i], REDIR) || ft_strchr(p->arg_id[*i],
					HEREDOC))
		{
			redir_lim[1] = (redir_lim[1] != begin) ? redir_lim[1] : *i;
			if (*i == 0)
			{
				ft_putendl("parse error");
				return (1);
			}
			else
				(*nb_redir)++;
		}
	}
	return (0);
}

char			**manage_redir(t_parse *p, int begin, char ***p_env)
{
	char	**commande;
	int		i;
	int		*redir_lim;
	int		nb_redir;

	commande = NULL;
	if (!(redir_lim = (int*)malloc(sizeof(int) * 2)))
		return (NULL);
	i = begin - 1;
	redir_lim[0] = begin;
	redir_lim[1] = begin;
	nb_redir = 0;
	if (p->arg[begin] && p->arg[begin][0])
	{
		if (manage_redir2(p, &i, redir_lim, &nb_redir))
			return (NULL);
		redir_lim[1] = (redir_lim[1] != begin) ? redir_lim[1] : i;
		ft_redir(p, redir_lim, *p_env, nb_redir);
		commande = create_commande(p, redir_lim[0], redir_lim[1]);
	}
	return (commande);
}
