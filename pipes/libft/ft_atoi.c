/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 14:27:35 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/30 14:44:33 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_begin_atoi(char const *s)
{
	size_t	i;
	size_t	begin;
	int		mem;

	if (ft_strlen(s) > 0)
	{
		i = 0;
		begin = 0;
		mem = 0;
		while (i < ft_strlen(s))
		{
			if ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\v'
						|| s[i] == '\f' || s[i] == '\r') && mem == 0)
				begin++;
			else
				mem = 1;
			i++;
		}
		return (begin);
	}
	return (0);
}

static char		*ft_strtrim_atoi(char const *s)
{
	char	*p;
	size_t	begin;

	if (ft_strlen(s) > 0)
	{
		begin = ft_begin_atoi(s);
		p = ft_strsub(s, begin, ft_strlen(s) - begin);
		return (p);
	}
	return (NULL);
}

static int		ft_atoi_mini(const char *str, size_t i)
{
	if (str[i + 1] == '2' && str[i + 2] == '1' && str[i + 3] == '4' &&
			str[i + 4] == '7' && str[i + 5] == '4' && str[i + 6] == '8'
			&& str[i + 7] == '3' && str[i + 8] == '6' && str[i + 8] == '4'
			&& str[i + 9] == '8' && (str[i + 10] > '9' || str[i + 10] < '0'))
		return (1);
	else
		return (0);
}

static long		ft_atoi_long(const char *str, size_t i, int neg)
{
	long	result;

	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((result == 922337203685477580 && neg == 1 && (str[i] - '0') > 7) ||
				(result > 922337203685477580 && neg == 1))
			return (-1);
		if ((result == 922337203685477580 && neg == -1 && (str[i] - '0') > 8) ||
				(result > 922337203685477580 && neg == -1))
			return (0);
		result = result * 10 + str[i++] - '0';
	}
	return (result * neg);
}

int				ft_atoi(const char *str)
{
	size_t	i;
	int		neg;
	long	result;

	if (ft_strlen(str) > 0)
	{
		str = ft_strtrim_atoi(str);
		i = 0;
		neg = 1;
		result = 0;
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
			{
				neg = -1;
				if (ft_atoi_mini(str, i))
					return (-2147483648);
			}
			i++;
		}
		result = ft_atoi_long(str, i, neg);
		ft_memdel((void**)&str);
		return ((int)result);
	}
	return (0);
}
