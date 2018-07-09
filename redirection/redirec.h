/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   redirec.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/09 12:12:20 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/09 12:12:56 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef REDIREC_H
# define REDIREC_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>

void		ft_fork_redirec(char ***tab, char **env, int nb_pipe);
void		ft_execve(char *path, char **tab, char **env);

#endif
