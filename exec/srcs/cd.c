/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cd.c                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <bpajot@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/04 10:50:52 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/25 12:17:36 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/exec.h"

static int		ft_cd3(char ***p_env, char *pwd, char *oldpwd)
{
	chdir(pwd);
	ft_setpwd(*p_env, 0, pwd);
	ft_setpwd(*p_env, 1, oldpwd);
	return (0);
}

static int		ft_cd2(char ***p_env, char *pwd, char *oldpwd, char **arg)
{
	struct stat		buf;
	char			*mem;
	int				ret;

	ret = 1;
	if (ft_strequ(arg[1], "-"))
		ret = ft_cd3(p_env, oldpwd, pwd);
	else
	{
		if (arg[1][0] != '/')
		{
			mem = ft_strjoin(pwd, "/");
			arg[1] = ft_strjoin(mem, arg[1]);
		}
		if (stat(arg[1], &buf) != 0)
			ft_printf("cd: no such file or directory: %s\n", arg[1]);
		else if (!(buf.st_mode & S_IFDIR) || (buf.st_mode & S_IFCHR))
			ft_printf("cd: not a directory: %s\n", arg[1]);
		else if (!(buf.st_mode & S_IROTH))
			ft_printf("cd: permission denied: %s\n", arg[1]);
		else
			ret = ft_cd3(p_env, arg[1], pwd);
	}
	return (ret);
}

int				ft_cd(char **arg, char ***p_env)
{
	char			*home;
	char			*pwd;
	char			*oldpwd;
	int				ret;

	ret = 1;
	home = ft_home(*p_env);
	pwd = ft_getpwd(*p_env, 0);
	oldpwd = ft_getpwd(*p_env, 1);
	if (!arg[1])
		if (home)
			ret = ft_cd3(p_env, home, pwd);
		else
			ft_putendl("cd: HOME not set");
	else if (!arg[2])
		ret = ft_cd2(p_env, pwd, oldpwd, arg);
	else
		ft_putendl("cd: too many arguments");
	ft_memdel((void**)&home);
	ft_memdel((void**)&pwd);
	ft_memdel((void**)&oldpwd);
	return (ret);
}
