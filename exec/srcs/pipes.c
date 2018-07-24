/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pipes.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/19 11:15:08 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/24 14:05:21 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/exec.h"

static void		display(char ***tab_pipe)
{
	int		i;
	int		j;

	i = -1;
	while (tab_pipe[++i])
	{
		j = -1;
		dprintf(2, "pipe %d : ", i);
		while (tab_pipe[i][++j])
			dprintf(2, "%s ", tab_pipe[i][j]);
		dprintf(2, "\n");
	}
}

static char		***create_tab_pipe(t_parse *p, int begin, int nb_pipe)
{
	char	***tab_pipe;
	int		i;
	int		j;
	int		k;
	int		buf;

	tab_pipe = (char***)malloc(sizeof(char**) * (nb_pipe + 2));
	i = begin;
	j = 0;
	k = -1;
	while (p->arg[i] && !ft_strchr(p->arg_id[i], SEMICOLON))
	{
		if (!ft_strchr(p->arg_id[i], PIPE))
		{
			buf = i;
			while (p->arg[i] && !ft_strchr(p->arg_id[i], PIPE) &&
				!ft_strchr(p->arg_id[i], SEMICOLON))
				i++;
			tab_pipe[j] = (char**)malloc(sizeof(char*) * (i - buf + 1));
			i = buf;
			while (p->arg[i] && !ft_strchr(p->arg_id[i], PIPE) &&
				!ft_strchr(p->arg_id[i], SEMICOLON))
				tab_pipe[j][++k] = ft_strdup(p->arg[i++]);
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

int				ft_manage_pipe(t_parse *p, int begin, char ***p_env)
{
	int		i;
	int		nb_pipe;
	char	***tab_pipe;

	i = begin;
	nb_pipe = 0;
	if (p->arg[i] && !ft_strchr(p->arg_id[i], SEMICOLON)) //p->arg[i][0])
	{
		while (p->arg[i] && !ft_strchr(p->arg_id[i], SEMICOLON))
		{
			if (ft_strchr(p->arg_id[i], PIPE))
			{
				if (i == begin || ft_strchr(p->arg_id[i - 1], PIPE))
// si pipe en 1er argument ou si 2 pipes colles
				{
					ft_putendl("parse error");
					return (1);
				}
				else if (!p->arg[i + 1] || ft_strchr(p->arg_id[i + 1],
					SEMICOLON))
// si pipe en dernier argument
				{
					ft_putendl("pipe>");
					return (0);
				}
				else
					nb_pipe++;
			}
			i++;
		}
		dprintf(2, "nb_pipe = %d\n", nb_pipe);
		tab_pipe = create_tab_pipe(p, begin, nb_pipe);
		display(tab_pipe);
		ft_fork_shell(tab_pipe, p_env, nb_pipe);
	}
	return (0);
}

