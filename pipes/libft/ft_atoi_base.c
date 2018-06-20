/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/13 19:41:13 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/13 21:04:04 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

static int	ft_atoi_base2(const char *str, int str_base, int neg)
{
	int		result;
	int		i;
	int		valuebuff;

	result = 0;
	i = 0;
	while ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'f')
		|| (str[i] >= 'A' && str[i] <= 'F'))
	{
		if (str[i] >= 'a' && str[i] <= 'f')
			valuebuff = 10 + str[i] - 'a';
		else if (str[i] >= 'A' && str[i] <= 'F')
			valuebuff = 10 + str[i] - 'A';
		else
			valuebuff = str[i] - '0';
		if (valuebuff < str_base)
			result = result * str_base + valuebuff;
		else if (result == 214748364 && str[i] == '8' && neg == -1)
			return (-2147483648);
		else
			return (result * neg);
		i++;
	}
	return (result * neg);
}

int			ft_atoi_base(const char *str, int str_base)
{
	int		i;
	int		neg;

	neg = 1;
	i = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	return (ft_atoi_base2(&str[i], str_base, neg));
}
