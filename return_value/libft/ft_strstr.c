/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 14:36:01 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/21 14:36:03 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0')
	{
		return ((char*)haystack);
	}
	else
	{
		while (i < ft_strlen(haystack))
		{
			j = 0;
			while (haystack[i + j] == needle[j] && i + j <= ft_strlen(haystack))
			{
				if (j + 1 == ft_strlen(needle))
					return ((char*)&haystack[i]);
				j++;
			}
			i++;
		}
	}
	return (NULL);
}
