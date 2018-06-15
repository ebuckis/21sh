/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parser.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/01 15:16:59 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/15 12:06:09 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_parser.h"

static int		ft_str_parser(t_parse *p)
{
	while (p->s[p->i])
	{
		if (p->s[p->i] == 92)
			p->err = ft_antislash(p);
		else if (p->s[p->i] == 34)
			p->err = ft_parse_dquote(p);
		else if (p->s[p->i] == 39)
			p->err = ft_parse_quote(p);
		else if (ft_is_separator(p))
			p->err = ft_separator(p);
		else if (ft_is_white(p->s[p->i]))
		{
			p->str[p->j] = -1;
			p->ident[p->j] = -1;
			p->i++;
			p->j++;
		}
		else
			ft_end_while(p, 1);
		if (p->err == 0)
			return (0);
	}
	return (1);
}

t_parse		*ft_parser(char *line)
{
	t_parse	*p;

	p = NULL;
	if (line)
	{
		if (!(p = ft_init_parse(line)))
			return (NULL);
		if (!ft_str_parser(p))
		{
			ft_close_parse();
			return (NULL);
		}
		p->arg = ft_strsplit(p->str, -1);
		p->arg_id = ft_strsplit(p->ident, -1);
		if (!p->arg && !p->arg_id)
			return (NULL);
	}
	return (p);
}
