/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_historique.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/10 16:32:27 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/10 18:16:47 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_edition.h"

t_hist		*ft_init_hist(void)
{
	t_hist	*h;

	h = (t_hist *)malloc(sizeof(t_hist));
	h->str = NULL;
	h->next = NULL;
	h->prev = NULL;
	return (h);
}

char	*ft_give_historique(int i)
{


}

t_hist	*ft_new_hist

char	*ft_historique(char *cmd)
{
	static t_hist	*h = NULL;

	if (!h)
		h = ft_init_hist();
	else
	{
		h = ft_new_hist(h);
	}
}
