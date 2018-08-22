/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_dollar.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/22 14:11:36 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/22 14:23:43 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_parser.h"

static void			ft_end_dollar(t_parse *p, t_doll *d, int i, int j)
{
	ft_strdel(&(p->arg[i]));
	ft_strdel(&(d->tmp));
	dprintf(2, "arg = %s\n", d->arg);
	ft_strdel(&(p->arg[i]));
	p->arg[i] = ft_strdup(d->arg);
	ft_strdel(&(d->arg));
	ft_strdel(&(p->arg_id[i]));
	p->arg_id[i] = ft_memalloc(ft_strlen(p->arg[i]) + 1);
	ft_bzero((void*)p->arg_id[i], ft_strlen(p->arg[i]) + 1);
	ft_memset((void*)p->arg_id[i], WORD, ft_strlen(p->arg[i]));
	ft_strdel(&(d->var));
	ft_strdel(&(d->key));
}

static void			ft_getvalue_var(t_parse *p, t_doll *d, int i, int j)
{
	if (d->p1 && d->p2 && d->p2 > d->p1)
		d->var = ft_strsub(d->p1, 1, d->p2 - d->p1 - 1);
	else if (d->p3)
		d->var = ft_strsub(&(p->arg[i][j + 1]), 0, d->p3 - &(p->arg[i][j + 1]));
	else
		d->var = ft_strdup(&(p->arg[i][j + 1]));
}

t_parse		*ft_dollar(t_parse *p, int i, int j, char **env)
{
	t_doll	d;

	d.p1 = ft_strchr(&(p->arg[i][j + 1]), '{');
	d.p2 = ft_strchr(&(p->arg[i][j + 1]), '}');
	d.p3 = ft_strchr(&(p->arg[i][j + 1]), '$');
	ft_getvalue_var(p, &d, i, j);
dprintf(2, "var = %s\n", d.var);
	d.key = (ft_strequ(d.var, "?")) ?
		ft_itoa(p->ret) : ft_strdup(getenv(d.var));
dprintf(2, "key = %s\n", d.key);
	if (j)
		d.tmp = ft_strjoin(ft_strsub(p->arg[i], 0, j), d.key);
	else
		d.tmp = (d.key) ? ft_strdup(d.key) : ft_strdup("");
	d.arg = (d.p1 && d.p2 && d.p2 > d.p1) ? ft_strjoin(d.tmp,
		&(p->arg[i][j + 1]) + ft_strlen(d.var) + 2) : ft_strdup(d.tmp);
	if (d.p1 && d.p2 && d.p2 > d.p1)
		d.arg = ft_strjoin(d.tmp, &(p->arg[i][j + 1]) + ft_strlen(d.var) + 2);
	else if (d.p3)
		d.arg = ft_strjoin(d.tmp, &(p->arg[i][j + 1]) + ft_strlen(d.var));
	else
		d.arg = ft_strdup(d.tmp);
	ft_end_dollar(p, &d, i, j);
	return (p);
}
