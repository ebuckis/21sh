/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pipes.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/19 11:15:08 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/21 16:30:26 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/exec.h"

static void			display(char ***tab_pipe)
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
		dprintf(2, "%s ", tab_pipe[i][j]);
		dprintf(2, "\n");
	}
	dprintf(2, "pipe %d : %p\n", i, tab_pipe[i]);
}

static void			create_tab_pipe2(t_parse *p, int *i, int j,
		char ***tab_pipe)
{
	int		buf;

	buf = *i;
	while (p->arg[*i] && !ft_strchr(p->arg_id[*i], PIPE) &&
		!ft_strchr(p->arg_id[*i], SEMICOLON))
		(*i)++;
	tab_pipe[j] = (char**)malloc(sizeof(char*) * (*i - buf + 1));
	*i = buf;
}

static char			***create_tab_pipe(t_parse *p, int i, int nb_pipe,
		char ***tab_pipe)
{
	int		j;
	int		k;

	tab_pipe = (char***)malloc(sizeof(char**) * (nb_pipe + 2));
	j = 0;
	k = -1;
	while (p->arg[i] && !ft_strchr(p->arg_id[i], SEMICOLON))
	{
		if (!ft_strchr(p->arg_id[i], PIPE))
		{
			create_tab_pipe2(p, &i, j, tab_pipe);
			while (p->arg[i] && !ft_strchr(p->arg_id[i], PIPE) &&
				!ft_strchr(p->arg_id[i], SEMICOLON))
				tab_pipe[j][++k] = ft_strdup(p->arg[i++]);
			tab_pipe[j++][++k] = NULL;
			k = -1;
		}
		else
			i++;
	}
	tab_pipe[j] = NULL;
	return (tab_pipe);
}

void				ft_manage_pipe(t_parse *p, int begin, char ***p_env)
{
	int		i;
	int		nb_pipe;
	char	***tab_pipe;

	i = begin;
	nb_pipe = 0;
	if (p->arg[i] && !ft_strchr(p->arg_id[i], SEMICOLON))
	{
		while (p->arg[i] && !ft_strchr(p->arg_id[i], SEMICOLON))
		{
			if (ft_strchr(p->arg_id[i], PIPE))
			{
				if (i == begin || ft_strchr(p->arg_id[i - 1], PIPE) ||
					!p->arg[i + 1] || ft_strchr(p->arg_id[i + 1], SEMICOLON))
				{
					ft_putendl("parse error");
					return ;
				}
				else
					nb_pipe++;
			}
			i++;
		}
		dprintf(2, "nb_pipe = %d\n", nb_pipe);
		tab_pipe = create_tab_pipe(p, begin, nb_pipe, tab_pipe);
		display(tab_pipe);
		ft_fork_shell(p, tab_pipe, p_env, nb_pipe);
		ft_free_tab3(tab_pipe);
		tab_pipe = NULL;
	}
}
