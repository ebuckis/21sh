/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cd.c                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <bpajot@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/04 10:50:52 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/10 11:40:49 by bpajot      ###    #+. /#+    ###.fr     */
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
	char			*path;
	int				ret;

	ret = 1;
	if (ft_strequ(arg[1], "-"))
		ret = ft_cd3(p_env, oldpwd, pwd);
	else
	{
		mem = ft_strjoin(pwd, "/");
		path = (arg[1][0] == '/') ? ft_strdup(arg[1]) : ft_strjoin(mem, arg[1]);
		ft_memdel((void**)&mem);
		if (stat(path, &buf) != 0)
			ft_printf("cd: no such file or directory: %s\n", path);
		else if (!(buf.st_mode & S_IFDIR) || (buf.st_mode & S_IFCHR))
			ft_printf("cd: not a directory: %s\n", path);
		else if (!(buf.st_mode & S_IROTH))
			ft_printf("cd: permission denied: %s\n", path);
		else
			ret = ft_cd3(p_env, path, pwd);
		ft_memdel((void**)&path);
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
