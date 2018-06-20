/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_is_prime.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 14:37:43 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/21 14:37:48 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	int i;

	i = 3;
	if (nb <= 1)
		return (0);
	if (nb == 2 || nb == 3 || nb == 2147483647)
		return (1);
	if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	while (nb % i != 0 && i * i < nb)
	{
		i = i + 2;
		if (nb % i == 0)
		{
			return (0);
		}
	}
	return (1);
}
