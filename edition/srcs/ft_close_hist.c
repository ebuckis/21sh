/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_close_hist.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/12 16:32:16 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/13 14:43:55 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_edition.h"

static void			ft_free_hist(t_hist *h)
{
	if (!h)
		return ;
	ft_free_hist(h->next);
	h->next = NULL;
	if (h->str)
		ft_strdel(&(h->str));
	h->prev = NULL;
	free(h);
}

t_hist				*ft_close_hist(int i, t_hist *list)
{
	static t_hist	*h = NULL;

	if (i == 0)
		h = list;
	if (i == CLOSE_HIST)
		ft_free_hist(h);
	else
		return (h);
	return (NULL);
}
