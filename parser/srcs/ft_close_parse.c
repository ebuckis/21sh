/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_close_parse.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/15 11:39:36 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/26 16:28:33 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_free_tab(char **t)
{
	int		i;

	if (!t)
		return ;
	i = 0;
	while (t[i])
	{
		free(t[i]);
		t[i] = NULL;
		i++;
	}
	free(t);
	t = NULL;
}

int			ft_close_parse(void)
{
	t_parse		*p;

	p = ft_save_struct(NULL);
	free(p->s);
	free(p->str);
	free(p->ident);
	ft_free_tab(p->arg);
	ft_free_tab(p->arg_id);
	free(p);
	p = NULL;
	return (1);
}

/*
** ft_close_parse peut etre appelée meme apres la sortie de la fonction
** afin de free la structure.
*/
