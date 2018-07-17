/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cd.c                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <bpajot@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/04 10:50:52 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/17 13:37:26 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "redirec.h"

static void		ft_cd3(char **env, char *pwd, char *oldpwd)
{
	chdir(pwd);
	ft_setpwd(env, 0, pwd);
	ft_setpwd(env, 1, oldpwd);
}

static void		ft_cd2(char **env, char *pwd, char *oldpwd, char **tab)
{
	struct stat		buf;

	if (ft_strequ(tab[1], "-"))
		ft_cd3(env, oldpwd, pwd);
	else if (stat(tab[1], &buf) != 0)
		ft_printf("cd: no such file or directory: %s\n", tab[1]);
	else if (!(buf.st_mode & S_IFDIR) || (buf.st_mode & S_IFCHR))
		ft_printf("cd: not a directory: %s\n", tab[1]);
	else if (!(buf.st_mode & S_IROTH))
		ft_printf("cd: permission denied: %s\n", tab[1]);
	else
		ft_cd3(env, tab[1], pwd);
}

int				ft_cd(char **tab, char **env)
{
	char			*home;
	char			*pwd;
	char			*oldpwd;

	home = ft_home(env);
	pwd = ft_getpwd(env, 0);
	oldpwd = ft_getpwd(env, 1);
	if (!tab[1])
		if (home)
			ft_cd3(env, home, pwd);
		else
			ft_putendl("cd: HOME not set");
	else if (!tab[2])
		ft_cd2(env, pwd, oldpwd, tab);
	else
		ft_putendl("cd: too many arguments");
	ft_memdel((void**)&home);
	ft_memdel((void**)&pwd);
	ft_memdel((void**)&oldpwd);
	return (1);
}
