/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_give_hist.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/12 16:27:53 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/12 18:34:03 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_edition.h"

char	*ft_give_hist(int i, t_hist *list)
{
	static t_hist	*h = NULL;
	static t_hist	*h_actual = NULL;//voir l'utilité

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
