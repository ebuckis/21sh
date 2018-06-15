/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parse_suite.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/07 12:37:54 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/15 11:04:15 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_parser.h"

int			ft_suite_line(t_parse *p, int i)
{
	char	*tmp;
	int		n;

	n = 0;
	tmp = NULL;
	if (i == 0)
		p->i++;
	if (i == 1)
	{
		n += 2;
		p->s = ft_strjoin_del(p->s, "\\n");//peut etre a remplacer
	}
	get_next_line(0, &tmp);
	p->s = ft_strjoin_del(p->s, tmp);
	if (ft_strlen(tmp) != 0 || n != 0)
	{
		p->len += n + ft_strlen(tmp);
		p->str = ft_realloc(p->str, p->len);
		p->ident = ft_realloc(p->ident, p->len);
	}
	free(tmp);
	return (1);
}

void		ft_end_while(t_parse *p, int n)
{
	p->str[p->j] = p->s[p->i];
	p->ident[p->j] = n + '0';
	p->i++;
	p->j++;
}
