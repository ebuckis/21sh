/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parse_suite.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/07 12:37:54 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/14 18:19:29 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_parse		*ft_init_parse(char *s)
{
	t_parse	*p;

	p = (t_parse *)malloc(sizeof(t_parse));
	if (!p)
		return (NULL);
	p->str = ft_strnew(ft_strlen(s) + 1);
	if (!p->str)
		return (NULL);
	p->ident = ft_strnew(ft_strlen(s) + 1);
	if (!p->ident)
		return (NULL);
	p->i = 0;
	p->j = 0;
	p->len = ft_strlen(s);
	return (p);
}

char		*ft_suite_line(t_parse *p, char *s, int i)
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
		s = ft_strjoin_del(s, "\\n");//peut etre a remplacer
	}
	get_next_line(0, &tmp);
	s = ft_strjoin_del(s, tmp);
	if (ft_strlen(tmp) != 0 || n != 0)
	{
		p->len += n + ft_strlen(tmp);
		p->str = ft_realloc(p->str, p->len);
		p->ident = ft_realloc(p->ident, p->len);
	}
	free(tmp);
	return (s);
}

void		ft_end_while(t_parse *p, char *s, int n)
{
	p->str[p->j] = s[p->i];
	p->ident[p->j] = n + '0';
	p->i++;
	p->j++;
}
