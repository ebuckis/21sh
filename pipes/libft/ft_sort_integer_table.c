/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sort_integer_table.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 14:32:40 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/21 14:32:42 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_integer_table(int *tab, int size)
{
	int i;
	int j;
	int min;
	int posmin;

	i = -1;
	while (++i < size - 1)
	{
		j = i;
		min = tab[i];
		while (++j < size)
		{
			if (tab[j] < min)
			{
				min = tab[j];
				posmin = j;
			}
		}
		if (min < tab[i])
		{
			ft_swap(tab + i, tab + posmin);
		}
	}
}
