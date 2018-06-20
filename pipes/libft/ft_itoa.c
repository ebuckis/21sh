/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 14:26:21 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/21 14:26:53 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len_itoa(int n)
{
	size_t	len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	len++;
	return (len);
}

static char		*ft_itoa_2(int n, size_t i, char *p)
{
	int		pow;
	int		nb;

	pow = 1;
	if (n < 0)
	{
		p[0] = '-';
		n = -n;
	}
	pow = 1;
	nb = n;
	while (pow <= n)
	{
		p[i--] = nb % 10 + '0';
		nb = nb / 10;
		if (pow == 1000000000)
			return (p);
		pow = pow * 10;
	}
	return (p);
}

char			*ft_itoa(int n)
{
	size_t	i;
	char	*p;

	if (n == -2147483648)
	{
		p = ft_strnew(11);
		if (p == NULL)
			return (NULL);
		ft_strcpy(p, "-2147483648");
		return (p);
	}
	i = ft_len_itoa(n) - 1;
	p = ft_strnew(i + 1);
	if (p == NULL)
		return (NULL);
	else if (n == 0)
		ft_strcpy(p, "0");
	else
		p = ft_itoa_2(n, i, p);
	return (p);
}
