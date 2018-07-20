/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cd.c                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <bpajot@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/04 10:50:52 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/19 16:10:49 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "21sh.h"

static void		ft_cd3(char **env, char *pwd, char *oldpwd)
{
	chdir(pwd);
	ft_setpwd(env, 0, pwd);
	ft_setpwd(env, 1, oldpwd);
}

static void		ft_cd2(char **env, char *pwd, char *oldpwd, char **arg)
{
	struct stat		buf;

	if (ft_strequ(arg[1], "-"))
		ft_cd3(env, oldpwd, pwd);
	else if (stat(arg[1], &buf) != 0)
		ft_printf("cd: no such file or directory: %s\n", arg[1]);
	else if (!(buf.st_mode & S_IFDIR) || (buf.st_mode & S_IFCHR))
		ft_printf("cd: not a directory: %s\n", arg[1]);
	else if (!(buf.st_mode & S_IROTH))
		ft_printf("cd: permission denied: %s\n", arg[1]);
	else
		ft_cd3(env, arg[1], pwd);
}

int				ft_cd(char **arg, char **env)
{
	char			*home;
	char			*pwd;
	char			*oldpwd;

	home = ft_home(env);
	pwd = ft_getpwd(env, 0);
	oldpwd = ft_getpwd(env, 1);
	if (!arg[1])
		if (home)
			ft_cd3(env, home, pwd);
		else
			ft_putendl("cd: HOME not set");
	else if (!arg[2])
		ft_cd2(env, pwd, oldpwd, arg);
	else
		ft_putendl("cd: too many arguments");
	ft_memdel((void**)&home);
	ft_memdel((void**)&pwd);
	ft_memdel((void**)&oldpwd);
	return (1);
}
