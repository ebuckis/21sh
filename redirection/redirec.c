/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   redirec.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/09 12:13:02 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/10 11:20:17 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "redirec.h"

static void		display(char ***tab)
{
	int		i;
	int		j;

	i = -1;
	while (tab[++i])
	{
		j = -1;
		ft_printf("commande %d : ", i);
		while (tab[i][++j])
		{
			ft_printf("%s ", tab[i][j]);
		}
		ft_putendl("");
	}
}

static char		***create_tab_redirec(char **tab, int nb_redir)
{
	char	***tab_redir;
	int		i;
	int		j;
	int		k;
	int		buf;

	tab_redir = (char***)malloc(sizeof(char**) * (nb_redir + 2));
	i = 0;
	j = 0;
	k = -1;
	while (tab[i])
	{
		if (ft_strcmp(tab[i], "|"))
		{
			buf = i;
			while (tab[i] && ft_strcmp(tab[i], "|"))
				i++;
			tab_redir[j] = (char**)malloc(sizeof(char*) * (i - buf + 1));
			i = buf;
			while (tab[i] && ft_strcmp(tab[i], "|"))
				tab_redir[j][++k] = ft_strdup(tab[i++]);
			tab_redir[j][++k] = NULL;
			j++;
			k = -1;
		}
		else
			i++;
	}
	tab_redir[j] = NULL;
	return (tab_redir);
}

int				main(int argc, char **argv, char **env)
{
	int		ret;
	char	***tab_redirec;
	char	**tab;
	int		i;
	int		nb_redirec;
	char	*line;

	argc++;
	argv++;
	ret = 0;
	i = -1;
	nb_redirec = 0;
	ft_putstr("$> ");
	get_next_line(0, &line);
	tab = ft_strsplit(line, ' ');
	if (tab && tab[0] && tab[0][0])
	{
		while (tab[++i])
		{
			if (ft_strchr(tab[i], '>') || ft_strchr(tab[i], '<'))
			{
				if (i == 0 || !tab[i + 1])
				{
					ft_putendl("parse error");
					return (1);
				}
				else
					nb_redirec++;
			}
		}
		ft_printf("nb_redirec = %d\n", nb_redirec);
		tab_redirec = create_tab_redirec(tab, nb_redirec);
		display(tab_redirec);
		ft_fork_redirec(tab_redirec, env, nb_redirec);
	}
	else
		ft_putendl("argument missing");
	return (0);
}
