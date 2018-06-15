/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_suite_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/15 13:54:21 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/15 14:20:37 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_parser.h"

int			ft_suite_line(t_parse *p, int i)
{
	char	*tmp;

	tmp = NULL;
	if (i == 0)
		p->i++;
	if (i == 1)
	{
		i = 2;
		if (!(p->s = ft_strjoin_del(p->s, "\n")))
			return (0);
	}
	get_next_line(0, &tmp);
	if (!(p->s = ft_strjoin_del(p->s, tmp)))
		return (0);
	if (ft_strlen(tmp) != 0 || i != 0)
	{
		p->len += i + ft_strlen(tmp);
		p->str = ft_realloc(p->str, p->len);
		p->ident = ft_realloc(p->ident, p->len);
		if (!p->str || !p->ident)
			return (0);
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

void		ft_add_space(t_parse *p)
{
	p->str[p->j] = -1;
	p->ident[p->j] = -1;
	p->j++;
}
