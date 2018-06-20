/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putchar_fd.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 14:31:32 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/21 14:31:34 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	unsigned char	ch;

	if (c >= 0)
		write(fd, &c, 1);
	else
	{
		ch = c + 128;
		if (ch >= 64)
		{
			c = 0xc3;
			write(fd, &c, 1);
			ch = ch - 64;
		}
		else
		{
			c = 0xc2;
			write(fd, &c, 1);
		}
		c = 0x80;
		c = c + ch;
		write(fd, &c, 1);
	}
}
