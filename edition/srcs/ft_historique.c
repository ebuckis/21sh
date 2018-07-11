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

static t_hist		*ft_init_hist(void)
{
	t_hist	*h;

	if (!(h = (t_hist *)malloc(sizeof(t_hist))))
		return (NULL);
	h->str = NULL;
	h->next = NULL;
	h->prev = NULL;
	return (h);
}

static t_hist		*ft_new_hist(char *s, t_hist *m_prev, t_hist *m_next)
{
	t_hist	*h;

	if (!(h = (t_hist *)malloc(sizeof(t_hist))))
		return (NULL);
	if (!(h->str = ft_strdu(s)))
		return (NULL);
	h->next = m_next;
	h->prev = m_prev;
	if (m_prev)
		m_prev->prev = h;
	return (h);
}

int			ft_add_hist(t_hist *h, char *s)
{
	static t_hist	*h = NULL;

	h = ft_init_hist();
	ft_close_hist(0, h);
	ft_give_historique(0, h);
	if (!s)
		return (0);
	h->next = ft_new_hist(s, h, h->next);
	return (1);
}

char	*ft_give_historique(int i, t_hist *list)
{
	static t_hist	*h = NULL;
	static t_hist	*h_actual = NULL;

	if (i == 0)
	{
		h = list;
		h_actual = h;
	}
	else if (i == 1 && h->next)
		h = h->next;
	else if (i == -1 && h->prev)
		h = h->prev;
	else
		return (NULL);
	return (h->str);
}

void		ft_close_hist(int i, t_hist *list)
{
	static t_hist	*h = NULL;

	if (i == 0)
	{
		h = list;
		return (NULL);
	}
	else
		return (h);
}
