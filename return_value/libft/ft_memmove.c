/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 14:31:11 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/21 14:31:13 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void		*ft_memcpyinv(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*strsrc;
	unsigned char	*strdst;

	strsrc = (unsigned char*)src;
	strdst = (unsigned char*)dst;
	i = 0;
	while (i < n)
	{
		strdst[n - i - 1] = strsrc[n - i - 1];
		i++;
	}
	return (dst);
}

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
		ft_memcpyinv(dst, src, len);
	return (dst);
}
