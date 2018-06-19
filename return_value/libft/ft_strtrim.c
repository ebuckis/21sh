/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 14:36:16 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/21 14:36:17 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_begin(char const *s)
{
	size_t	i;
	size_t	begin;
	int		mem;

	if (s != NULL && s[0] != '\0')
	{
		i = 0;
		begin = 0;
		mem = 0;
		while (i < ft_strlen(s))
		{
			if ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && mem == 0)
				begin++;
			else
				mem = 1;
			i++;
		}
		return (begin);
	}
	return (0);
}

static size_t	ft_end(char const *s)
{
	size_t	i;
	size_t	end;
	int		mem;

	if (s != NULL && s[0] != '\0')
	{
		i = ft_strlen(s) - 1;
		end = i;
		mem = 0;
		while (i > 0)
		{
			if ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && mem == 0)
				end--;
			else
				mem = 1;
			i--;
		}
		return (end);
	}
	return (0);
}

char			*ft_strtrim(char const *s)
{
	char	*p;
	size_t	begin;
	size_t	end;

	if (s != NULL)
	{
		begin = ft_begin(s);
		end = ft_end(s);
		if (end > begin)
		{
			p = ft_strsub(s, begin, end - begin + 1);
			return (p);
		}
		else
		{
			p = ft_strnew(0);
			return (p);
		}
	}
	return (NULL);
}
