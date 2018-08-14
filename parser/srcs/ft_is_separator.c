/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_is_separator.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/15 10:15:12 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/14 13:01:21 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_parser.h"

int	ft_is_redirection(char c)
{
	if (c == ';')
		return (1);
	else if (c == '|')
		return (1);
	else if (c == '&')
		return (1);
	else if (c == '<')
		return (1);
	else if (c == '>')
		return (1);
	else
		return (0);
}

int			ft_is_separator(t_parse *p)
{
	int		i;

	i = p->i;
	if (p->i == 0 || p->s[p->i - 1] != -1)
	{
		while (ft_isdigit(p->s[i]))
			i++;
		if (ft_is_redirection(p->s[i]))
			return (1);
		else
			return (0);
	}
	else
	{
		if (ft_is_redirection(p->s[p->i]))
			return (1);
		else
			return (0);
	}
}

/*
** On verrifie de maniere booleenne si on est sur un separteur/redirection
** 2 cas :
** 			- le premier char est un chiffre
**			- le premier char est un char de la 1ere fonction
*/
