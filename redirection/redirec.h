/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   redirec.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/09 12:12:20 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/21 16:06:44 by kcabus      ###    #+. /#+    ###.fr     */
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
void		ft_execve(char **tab, char **env);
void		ft_setpwd(char **env, int old, char *pwd);
char		*ft_getpwd(char **env, int old);
char		**ft_getenv(int argc, char *argv[], char *env[]);
char		*ft_home(char **env);
int			ft_cd(char **tab, char **env);
//void		ft_free_tab(char **tab);
char		*check_bin(char **tab, char **env);
char		*check_bin2(char *tab0, char **env);
char		*check_bin3(char *bin, int warning);
int			check_builtin(char **tab, char ***env);
int			ft_echo(char **tab);
void		ft_env(char **tab, char **env);
char		**ft_mix_env(char **env, char **env2);
void		ft_exit(char **tab, char **env, int i);
char		*ft_strjoin2(char *line);
char		*ft_strjoin3(char *line1, char *line2, int i);
void		display_env(char **env);
void		ft_setenv(char **tab, char ***env);
void		ft_setenv2(char **tab, char ***env);
void		ft_unsetenv(char **tab, char ***env);
void		ft_fork(char *path, char **tab, char **env);

#endif
