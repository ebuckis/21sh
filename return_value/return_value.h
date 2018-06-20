/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   return_value.h                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/19 09:31:40 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/19 09:52:01 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef RETURN_VALUE_H
# define RETURN_VALUE_H

# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>

int			ft_fork(char *path, char **tab, char **env);
int			ft_execve(char *path, char **tab, char **env);

#endif
