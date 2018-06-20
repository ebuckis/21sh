/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pipes.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/19 11:15:24 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/20 16:06:03 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PIPES_H
# define PIPES_H

# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>

int			ft_fork_pipe(char ***tab, char **env, int nb_pipe);
int			ft_execve(char *path, char **tab, char **env);

#endif
