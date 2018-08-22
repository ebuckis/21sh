/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   manage_redir.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/23 13:32:33 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/22 15:03:07 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/exec.h"

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

static char		**create_redir(t_parse *p, int sep, int size)
{
	int		i;
	char	**redir;

	redir = (char**)malloc(sizeof(char*) * (size - sep + 1));
	i = - 1;
	while (++i < size - sep)
		redir[i] = ft_strdup(p->arg[i + sep]);
	redir[i] = NULL;
	return (redir);
}

char			**manage_redir(t_parse *p, int begin, char ***p_env)
{
	char	**commande;
	char	**redir;
	int		i;
	int		sep;
	int		nb_redir;

	dprintf(2, "begin = %d\n", begin);
	i = begin - 1;
	sep = begin;
	nb_redir = 0;
	if (p->arg[begin] && p->arg[begin][0])
	{
		while (p->arg[++i] && p->arg_id[i][0] < PIPE)
		{
			if (ft_strchr(p->arg_id[i], REDIR) || ft_strchr(p->arg_id[i],
				HEREDOC))
			{
				sep = (sep != begin) ? sep : i;
				if (i == 0)
				{
					ft_putendl("parse error");
					return (NULL);
				}
				else
					nb_redir++;
			}
		}
		sep = (sep != begin) ? sep : i;
		dprintf(2, "nb_redir = %d\n", nb_redir);
		dprintf(2, "begin = %d, sep = %d, size = %d\n", begin, sep, i);
		commande = create_commande(p, begin, sep);
		redir = create_redir(p, sep, i);
		dprintf(2, "commande + arg :\n");
		display(commande);
		dprintf(2, "redir :\n");
		display(redir);
		ft_redir(commande, redir, *p_env, nb_redir);
	}
	return (commande);
}
