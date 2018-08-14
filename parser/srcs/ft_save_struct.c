/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_save_struct.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/15 11:30:42 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/14 13:00:50 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_parser.h"

t_parse		*ft_save_struct(t_parse *parsing)
{
	static t_parse	*p = NULL;

	if (parsing)
		p = parsing;
	return (p);
}

/*
** On enregistre la structure dans une statique
** pour y avoir acces quand on veut
*/
