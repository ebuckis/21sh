/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pipes.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/19 11:15:08 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/22 14:28:56 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/exec.h"

static void			display(int *tab_pipe)
{
	int		i;

	i = -1;
	dprintf(2, "tab_pipe :\n");
	while (tab_pipe[++i] >= 0)
		dprintf(2, "tab_pipe[%d] = %d\n", i, tab_pipe[i]);
	dprintf(2, "tab_pipe[%d] = %d\n", i, tab_pipe[i]);
}

/*static void			create_tab_pipe2(t_parse *p, int *i, int j,
		char ***tab_pipe)
{
	int		buf;

	buf = *i;
	while (p->arg[*i] && !ft_strchr(p->arg_id[*i], PIPE) &&
		!ft_strchr(p->arg_id[*i], SEMICOLON))
		(*i)++;
	tab_pipe[j] = (char**)malloc(sizeof(char*) * (*i - buf + 1));
	*i = buf;
}*/

static int			*create_tab_pipe(t_parse *p, int i, int nb_pipe,
		int *tab_pipe)
{
	int		j;

	tab_pipe = (int*)malloc(sizeof(int) * (nb_pipe + 2));
	tab_pipe[0] = i;
	j = 1;
	while (p->arg[i] && !ft_strchr(p->arg_id[i], SEMICOLON))
	{
		if (ft_strchr(p->arg_id[i], PIPE))
			tab_pipe[j++] = ++i;
		else
			i++;
	}
	tab_pipe[j] = -1;
	return (tab_pipe);
}

void				ft_manage_pipe(t_parse *p, int begin, char ***p_env)
{
	int		i;
	int		nb_pipe;
	int 	*tab_pipe;

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
		dprintf(2, "begin = %d\n", begin);
		tab_pipe = create_tab_pipe(p, begin, nb_pipe, tab_pipe);
		display(tab_pipe);
		ft_fork_shell(p, tab_pipe, p_env, nb_pipe);
		ft_memdel((void**)&tab_pipe);
		tab_pipe = NULL;
	}
}
