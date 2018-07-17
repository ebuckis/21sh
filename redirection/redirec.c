/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   redirec.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/11 16:22:24 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/17 14:23:51 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "redirec.h"

static void		display(char **tab)
{
	int		i;

	i = -1;
	while (tab[++i])
		ft_printf("%s\n", tab[i]);
}

static char		**create_commande(char **tab, int size)
{
	int		i;
	char	**commande;

	commande = (char**)malloc(sizeof(char*) * (size + 1));
	i = -1;
	while (++i < size)
		commande[i] = ft_strdup(tab[i]);
	commande[i] = NULL;
	return (commande);
}

static char		**create_redir(char **tab, int sep, int size)
{
	int		i;
	char	**redir;

	redir = (char**)malloc(sizeof(char*) * (size - sep + 1));
	i = sep - 1;
	while (++i < size)
		redir[i - sep] = ft_strdup(tab[i]);
	redir[i - sep] = NULL;
	return (redir);
}

int				main(int argc, char **argv, char **env)
{
	char	**tab;
	char	**commande;
	char	**redir;
	int		i;
	int		sep;
	int		nb_redir;
	char	*line;
	char	**my_env;

	argc++;
	argv++;
	i = -1;
	sep = 0;
	nb_redir = 0;
	my_env = ft_getenv(argc, argv, env);
	ft_putstr("$> ");
	get_next_line(0, &line);
	tab = ft_strsplit(line, ' ');
	if (tab && tab[0] && tab[0][0])
	{
		while (tab[++i])
		{
			ft_printf("tab[%d] = \"%s\"\n", i, tab[i]);
			if (ft_strchr(tab[i], '>') || ft_strchr(tab[i], '<'))
			{
				sep = (sep) ? sep : i;
				if (i == 0) //|| (!tab[i + 1] &&  !ft_strchr(tab[i], '-')) ||
//					ft_strchr(tab[i + 1], '>') || ft_strchr(tab[i + 1], '<'))
// si redire en 1er ou dernier  argument ou si 2 redir colles
				{
					ft_putendl("parse error");
					return (1);
				}
				else
					nb_redir++;
			}
		}
		sep = (sep) ? sep : i;
		ft_printf("nb_redir = %d\n", nb_redir);
		ft_printf("sep = %d, size = %d\n", sep, i);
		commande = create_commande(tab, sep);
		redir = create_redir(tab, sep, i);
		ft_printf("commande + arg :\n");
		display(commande);
		ft_printf("redir :\n");
		display(redir);
		ft_manage_redir(commande, redir, my_env, nb_redir);
	}
	else
		ft_putendl("argument missing");
	return (0);
}
