/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 14:30:35 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/21 14:30:37 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*strsrc;
	unsigned char	*strdst;
	unsigned char	charc;

	strsrc = (unsigned char*)src;
	strdst = (unsigned char*)dst;
	charc = (unsigned char)c;
	i = 0;
	while (i < n && strsrc[i] != charc)
	{
		strdst[i] = strsrc[i];
		i++;
	}
	if (i < n && strsrc[i] == charc)
		strdst[i] = strsrc[i];
	if (i == n)
		return (NULL);
	else
		return (dst + i + 1);
}
