/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_verif_term_size.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/17 18:26:22 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/18 12:45:43 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_edition.h"

int		ft_verif_term_size(t_navig *n)
{
	int		nb;

	nb = ft_strlen(n->prompt) + ft_strlen(n->s) + 1;
	dprintf(2, "===========================\ni = %d\nnb = %d\nx_size = %d\ny_size = %d\n=============================\n", n->i, nb, n->x_size, n->y_size);
	if (nb == n->y_size * n->x_size)
		return (0);
	if (nb > n->y_size * n->x_size)
		return (-1);
	return (1);
}
