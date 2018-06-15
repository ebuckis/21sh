/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parse_dquote.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/15 10:21:39 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/15 10:21:58 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_parser.h"

int			ft_parse_dquote(t_parse *p)
{
	p->i++;
	while (1)
	{
		if (p->s[p->i] == 92)
		{
			if (p->s[p->i + 1] == 96 || p->s[p->i + 1] == '$'
				|| p->s[p->i + 1] == 92 || p->s[p->i + 1] == 34)
				p->i++;
			ft_end_while(p, 0);
		}
		else if (p->s[p->i] == 34)
		{
			p->i++;
			return (1);
		}
		else if (p->s[p->i] != '\0')
			ft_end_while(p, 0);
		else
		{
			ft_putstr("dquote> ");
			ft_suite_line(p, 1);
		}
	}
	return (1);
}
