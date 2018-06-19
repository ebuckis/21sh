/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   return_value.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/19 09:34:19 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/19 09:57:40 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "return_value.h"

int		main(int argc, char **argv, char **env)
{
	int		ret;

	ret = 0;
	if (argc > 1)
	{
		ret = ft_fork(argv[1], &argv[1], env);
		ft_printf("return_value = %d\n", ret);
	}
	else
		ft_putendl("argument missing");
	return (ret);
}
