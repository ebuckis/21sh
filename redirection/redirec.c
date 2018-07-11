/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   redirec.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/09 12:13:02 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/11 15:03:06 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "redirec.h"

static void		display(char **tab)
{
	int		i;

	i = -1;
	while (tab[++i])
	{
			ft_printf("%s", tab[i]);
		ft_putendl("");
	}
}

int				main(int argc, char **argv)//, char **env)
{
	int		ret;
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
				if (!tab[i + 1] || ft_strchr(tab[i + 1], '>') ||
					ft_strchr(tab[i + 1], '<'))
// si redirection en dernier parametre ou 2 redirections a la suite
				{
					ft_putendl("parse error");
					return (1);
				}
				else
					nb_redirec++;
			}
		}
		ft_printf("nb_redirec = %d\n", nb_redirec);
		display(tab);
		//ft_fork_redirec(tab, env, nb_redirec);
	}
	else
		ft_putendl("argument missing");
	return (0);
}
