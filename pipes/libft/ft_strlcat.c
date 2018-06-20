/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 14:34:22 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/21 14:34:24 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;

	i = 0;
	while (dst[i] != '\0' && i < size)
		i++;
	if (i == size && dst[i] != '\0')
		len_dst = size;
	else
		len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = 0;
	while (i < len_src && len_dst + i < (size - 1) && len_dst < size)
	{
		dst[i + len_dst] = src[i];
		i++;
	}
	if (len_dst + i <= size && len_dst < size && size != 0)
		dst[i + len_dst] = '\0';
	return (len_dst + len_src);
}
