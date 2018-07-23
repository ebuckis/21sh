/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   manage_redir.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/23 13:32:33 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/23 14:18:34 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/exec.h"

static void		display(char **tab_redir)
{
	int		i;

	i = -1;
	while (tab_redir[++i])
		dprintf(2, "%s\n", tab_redir[i]);
}

static char		**create_commande(char **tab_redir, int size)
{
	int		i;
	char	**commande;

	commande = (char**)malloc(sizeof(char*) * (size + 1));
	i = -1;
	while (++i < size)
		commande[i] = ft_strdup(tab_redir[i]);
	commande[i] = NULL;
	return (commande);
}

static char		**create_redir(char **tab_redir, int sep, int size)
{
	int		i;
	char	**redir;

	redir = (char**)malloc(sizeof(char*) * (size - sep + 1));
	i = sep - 1;
	while (++i < size)
		redir[i - sep] = ft_strdup(tab_redir[i]);
	redir[i - sep] = NULL;
	return (redir);
}

char			**manage_redir(char** tab_redir, char ***p_env)
{
	char	**commande;
	char	**redir;
	int		i;
	int		sep;
	int		nb_redir;
	char	*line;
	char	**my_env;

	i = -1;
	sep = 0;
	nb_redir = 0;
	if (tab_redir && tab_redir[0] && tab_redir[0][0])
	{
		while (tab_redir[++i])
		{
			dprintf(2, "tab_redir[%d] = \"%s\"\n", i, tab_redir[i]);
			if (ft_strchr(tab_redir[i], '>') || ft_strchr(tab_redir[i], '<'))
			{
				sep = (sep) ? sep : i;
				if (i == 0) //|| (!tab[i + 1] &&  !ft_strchr(tab[i], '-')) ||
//					ft_strchr(tab[i + 1], '>') || ft_strchr(tab[i + 1], '<'))
// si redire en 1er ou dernier  argument ou si 2 redir colles
				{
					ft_putendl("parse error");
					return (NULL);
				}
				else
					nb_redir++;
			}
		}
		sep = (sep) ? sep : i;
		dprintf(2, "nb_redir = %d\n", nb_redir);
		dprintf(2, "sep = %d, size = %d\n", sep, i);
		commande = create_commande(tab_redir, sep);
		redir = create_redir(tab_redir, sep, i);
		dprintf(2, "commande + arg :\n");
		display(commande);
		dprintf(2, "redir :\n");
		display(redir);
		ft_redir(commande, redir, *p_env, nb_redir);
	}
	return (commande);
}
