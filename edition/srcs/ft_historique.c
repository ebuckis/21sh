/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_historique.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/10 16:32:27 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/11 18:12: by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_edition.h"

static t_hist	*ft_init_hist(void)
{
	t_hist	*h;

	if (!(h = (t_hist *)malloc(sizeof(t_hist))))
		return (NULL);
	h->str = NULL;
	h->next = NULL;
	h->prev = NULL;
	return (h);
}

static t_hist	*ft_new_hist(char *s, t_hist *m_prev, t_hist *m_next)
{
	t_hist		*h;

	if (!(h = (t_hist *)malloc(sizeof(t_hist))))
		return (NULL);
	if (!(h->str = ft_strdup(s)))
		return (NULL);
	h->next = m_next;
	h->prev = m_prev;
	if (m_next)
		m_next->prev = h;
	return (h);
}

int				ft_add_hist(char *s)
{
	t_hist	*h;

	h = ft_close_hist(1, NULL);
	if (!h)
		return (0);
	if (!s)
		return (0);
	if (!h->next)
	{
		if (!(h->next = ft_new_hist(s, h, h->next)))
			return (0);
	}
	else if (ft_strcmp(s, h->next->str) != 0)
	{
		if (!(h->next = ft_new_hist(s, h, h->next)))
			return (0);
	}
	return (1);
}

int				ft_open_hist(void)
{
	t_hist	*h;

	if (!(h = ft_close_hist(1, NULL)))
	{
		if (!(h = ft_init_hist()))
			return (0);
		ft_give_hist(0, h);
		ft_close_hist(0, h);
	}
	else
		ft_give_hist(0, h);
	return (1);
}
