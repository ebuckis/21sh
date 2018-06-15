/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parse_quote.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/15 10:22:22 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/15 10:56:46 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_parser.h"

int			ft_parse_quote(t_parse *p)
{
	p->i++;
	while (1)
	{
		if (p->s[p->i] == 39)
		{
			p->i++;
			return (1);
		}
		else if (p->s[p->i] != '\0')
		{
			ft_end_while(p, 0);
		}
		while (p->s[p->i] == '\0')
		{
			ft_putstr("quote> ");
			ft_suite_line(p, 1);//verif
		}
	}
	return (1);
}
