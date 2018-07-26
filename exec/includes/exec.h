/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   exec.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/20 15:32:40 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/26 17:24:00 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "../../parser/includes/ft_parser.h"
# include "../../libft/includes/libft.h"
# include "../../edition/includes/ft_edition.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <locale.h>

int			ft_manage_pipe(t_parse *p, int begin, char ***p_env);
void		ft_fork_shell(t_parse *p, char ***tab_pipe, char ***p_env,
		int nb_pipe);
char		**manage_redir(char **tab_redir, char ***p_env);
void		ft_redir(char **commande, char **redirec, char **env,
		int nb_redirec);
int			check_builtin(char **tab_pipe_i);
void		run_builtin(t_parse *p, char **tab_pipe_i, char ***p_env,
		int in_pipe);
char		*check_bin(char **tab_pipe_i, char **env);
void		ft_execve(t_parse *p, char **tab_pipe_i, char ***p_env,
		int in_pipe);
char		**ft_getenv(int argc, char **argv, char **env);
char		*ft_home(char **env);
char		*ft_getpwd(char **env, int old);
void		ft_setpwd(char **env, int old, char *pwd);
int			ft_cd(char **arg, char ***p_env);
int			ft_echo(char **arg);
int			ft_env(t_parse *p, char **arg, char **env);
int			ft_fg(t_parse *p);
int			display_env(char **env);
char		**ft_mix_env(char **env, char **env2);
int			ft_doublon(char *line, char **arg, int j);
int			ft_tab_size(char **arg, char **tab_ref);
int			ft_setenv(char **arg, char ***env);
int			ft_unsetenv(char **arg, char ***env);
void		manage_signal(void);
void		ft_ret_display(t_parse *p, pid_t pid, int status);

#endif
