/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pipes.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/19 11:15:08 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/11 15:24:35 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "pipes.h"

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

static char		***create_tab_pipe(char **tab, int nb_pipe)
{
	char	***tab_pipe;
	int		i;
	int		j;
	int		k;
	int		buf;

	tab_pipe = (char***)malloc(sizeof(char**) * (nb_pipe + 2));
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
			tab_pipe[j] = (char**)malloc(sizeof(char*) * (i - buf + 1));
			i = buf;
			while (tab[i] && ft_strcmp(tab[i], "|"))
				tab_pipe[j][++k] = ft_strdup(tab[i++]);
			tab_pipe[j][++k] = NULL;
			j++;
			k = -1;
		}
		else
			i++;
	}
	tab_pipe[j] = NULL;
	return (tab_pipe);
}

int				main(int argc, char **argv, char **env)
{
	char	***tab_pipe;
	char	**tab;
	int		i;
	int		nb_pipe;
	char	*line;

	argc++;
	argv++;
	i = -1;
	nb_pipe = 0;
	ft_putstr("$> ");
	get_next_line(0, &line);
	tab = ft_strsplit(line, ' ');
	if (tab && tab[0] && tab[0][0])
	{
		while (tab[++i])
		{
			if (ft_strcmp(tab[i], "|") == 0)
			{
				if (i == 0 || ft_strcmp(tab[i - 1], "|") == 0)
// si pipe en 1er argument ou si 2 pipes colles
				{
					ft_putendl("parse error");
					return (1);
				}
				else if (!tab[i + 1])
// si pipe en dernier argument
				{
					ft_putendl("pipe>");
					return (0);
				}
				else
					nb_pipe++;
			}
		}
		ft_printf("nb_pipe = %d\n", nb_pipe);
		tab_pipe = create_tab_pipe(tab, nb_pipe);
		display(tab_pipe);
		ft_fork_pipe(tab_pipe, env, nb_pipe);
	}
	else
		ft_putendl("argument missing");
	return (0);
}
