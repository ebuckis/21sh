/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pipes.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/19 11:15:24 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/18 17:21:33 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PIPES_H
# define PIPES_H

# include "./parser/includes/ft_parser.h"
# include "./libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>

int			ft_manage_pipe(t_parse *p, int begin);
//void		ft_fork_pipe(char ***tab, char **env, int nb_pipe);
//void		ft_execve(char *path, char **tab, char **env);

#endif
