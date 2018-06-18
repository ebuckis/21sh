/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_is_white.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/15 10:12:23 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/18 14:50:21 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_parser.h"

int			ft_is_white(char c)
{
	if (c == ' ')
		return (1);
	else if (c == '\t')
		return (1);
	else if (c == '\n')
		return (1);
	else if (c == '\r')
		return (1);
	else if (c == '\v')
		return (1);
	return (0);
}

/*
** Verifie si c est un WhiteSpace
*/
