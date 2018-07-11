/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   redirec.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/09 12:12:20 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/11 18:30:50 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef REDIREC_H
# define REDIREC_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>

void		ft_manage_redir(char **commande, char **redirec, char **env,
		int nb_redirec);
void		ft_execve(char *path, char **tab, char **env);

#endif
