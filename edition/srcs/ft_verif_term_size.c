/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_verif_term_size.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/17 18:26:22 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/17 19:01:08 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_edition.h"

int		ft_verif_term_size(t_navig *n)
{
	int		nb;
	int		ynb;

	nb = ft_strlen(n->prompt) + ft_strlen(n->s) + 2;
	ynb = 1 + (nb / (n->x_size));
	dprintf(2, "===========================\nnb = %d\ny nb = %d\nx_size = %d\ny_size = %d\n=============================\n", nb, ynb, n->x_size, n->y_size);
	if (ynb > n->y_size)
		return (0);
	return (1);
}
