/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_x_change.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/22 15:54:46 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/22 18:30:01 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_edition.h"

void	ft_x_change(t_navig *n, int i)
{
	if (i == 2)
	{
		if (n->x < n->x_size)
			n->x++;
		else if (n->y < n->y_size)
		{
			n->x = 1;
			n->y++;
		}
	}
	else if (i == 1)
	{
		if (n->x < n->x_len)
			n->x++;
		else if (n->y < n->y_len)
		{
			n->x = 1;
			n->y++;
		}
	}
	else
	{
		if (n->x > n->x_start)
			n->x--;
		else if (n->y > n->y_start)
		{
			n->x = n->x_size;
			n->y--;
		}
	}
//	printf("adress x = %d\n", &(n->x));
//	printf("x = %d\n", n->x);
//	printf("y = %d\n", n->y);
//	printf("x_len = %d\n", n->x_len);
//	printf("y_len = %d\n", n->y_len);
//	printf("x_start = %d\n", n->x_start);
//	printf("y_start = %d\n", n->y_start);
//	printf("x_size = %d\n", n->x_size);
//	printf("y_size = %d\n", n->y_size);
}
// i == 1 -> ++ else -- if 2 on peut aller plus loin
