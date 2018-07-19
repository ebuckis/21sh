/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   21sh.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/19 15:28:26 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/19 16:16:18 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

//gcc main2.c pipes.c cd.c check_bin.c check_builtin.c echo.c env.c execve.c fork.c getenv.c setenv.c unsetenv.c libft/libft.a edition/libedition.a parser/libparser.a -ltermcap
//./a.out 2> /dev/ttys00?

#ifndef SH21_H
# define SH21_H

# include "./parser/includes/ft_parser.h"
# include "./libft/includes/libft.h"
# include "./edition/includes/ft_edition.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <locale.h>

int			ft_manage_pipe(t_parse *p, int begin, char ***p_env);
void		ft_fork_pipe(char ***tab_pipe, char ***p_env, int nb_pipe);
int			check_builtin(char **tab_pipe_i, char ***p_env);
char		*check_bin(char **tab_pipe_i, char **env);
void		ft_execve(char **tab_pipe_i, char ***p_env);
char		**ft_getenv(int argc, char **argv, char **env);
char		*ft_home(char **env);
char		*ft_getpwd(char **env, int old);
void		ft_setpwd(char **env, int old, char *pwd);
int			ft_cd(char **arg, char **env);
int			ft_echo(char **arg);
void		ft_env(char **arg, char **env);
void		display_env(char **env);
char		**ft_mix_env(char **env, char **env2);
void		ft_setenv(char **arg, char ***env);
void		ft_unsetenv(char **arg, char ***env);

#endif
