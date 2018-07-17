/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <bpajot@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/07 14:48:24 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/17 13:38:17 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "redirec.h"

void	ft_free_tab(char **tab)
{
	int		i;

	i = -1;
	if (tab)
	{
		while (tab[++i])
			ft_memdel((void**)&tab[i]);
		ft_memdel((void**)&tab);
	}
}

char	*ft_strjoin2(char *line)
{
	char	*tmp;

	tmp = ft_strjoin(line, "\n");
	ft_memdel((void**)&line);
	return (tmp);
}

char	*ft_strjoin3(char *line1, char *line2, int i)
{
	char	*tmp;

	tmp = ft_strjoin(line1, line2 + i);
	ft_memdel((void**)&line1);
	ft_memdel((void**)&line2);
	return (tmp);
}
