/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_close_parse.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/15 11:39:36 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/21 16:52:48 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_free_tab_2(char **t)
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
}

void	ft_free_tab(char ***t)
{
	ft_free_tab_2(*(t));
	*t = NULL;
}

void	ft_free_tab3(char ***t)
{
	int		i;

	if (!t)
		return ;
	i = 0;
	while (t[i])
	{
		ft_free_tab(&t[i]);
		i++;
	}
	free(t);
	t = NULL;
}

int		ft_close_parse(void)
{
	t_parse		**p;
	
	p = ft_save_struct(NULL);
	if (*p)
	{
		ft_strdel(&((*p)->s));
		ft_strdel(&((*p)->str));
		ft_strdel(&((*p)->ident));
		ft_free_tab(&((*p)->arg));
		ft_free_tab(&((*p)->arg_id));
		ft_free_tab(&((*p)->hdoc));
		if (*p)
			free(*p);
		*p = NULL;
	}
	return (1);
}

/*
** ft_close_parse peut etre appelée meme apres la sortie de la fonction
** afin de free la structure.
*/
