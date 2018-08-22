/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   env.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/04 14:50:45 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/22 13:36:33 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/exec.h"

int				ft_doublon(char *line, char **arg, int j)
{
	int		i;
	char	*p;
	char	*p2;
	char	*p3;
	char	*p4;

	i = j;
	p2 = ft_strchr(line, '=');
	while (arg[++i])
	{
		if ((p = ft_strchr(arg[i], '=')))
		{
			p3 = ft_strsub(arg[i], 0, p - arg[i]);
			p4 = ft_strsub(line, 0, p2 - line);
			if (ft_strequ(p3, p4))
			{
				ft_memdel((void**)&p3);
				ft_memdel((void**)&p4);
				return (1);
			}
			ft_memdel((void**)&p3);
			ft_memdel((void**)&p4);
		}
	}
	return (0);
}

int				ft_tab_size(char **arg, char **tab_ref)
{
	int		i;
	int		doublon;

	i = -1;
	doublon = 0;
	while (arg[++i])
		doublon += (tab_ref && (ft_doublon(arg[i], tab_ref, -1) ||
					ft_doublon(arg[i], arg, i))) ? 1 : 0;
	return (i - doublon);
}

static int		ft_env3(t_parse *p, char **arg, char **env, int i,
		int tab_pipe_i)
{
	pid_t	pid;
	int		status;
	char	*bin;

	if (arg[i])
	{
		if (check_builtin(&arg[i]))
			run_builtin(p, &arg[i], &env, tab_pipe_i);
		else
		{
			pid = fork();
			if (pid == 0)
				ft_execve(p, i, &env);//, 1);
			else if (pid > 0)
			{
				waitpid(pid, &status, WUNTRACED);
				ft_ret_display(p, pid, status);
			}
		}
		return (p->ret);
	}
	else
		display_env(env);
	return (0);
}

static int		ft_env2(t_parse *p, char **arg, char **env, int tab_pipe_i)
{
	int		i;
	int		option_i;
	char	**env2;
	char	**env3;
	int		ret;

	i = -1;
	option_i = (ft_strequ(arg[1], "-i")) ? 1 : 0;
	i = option_i;
	while (arg[++i] && ft_strchr(arg[i], '='))
		;
	env2 = (char**)malloc(sizeof(char*) * i);
	i = option_i;
	while (arg[++i] && ft_strchr(arg[i], '='))
		env2[i - option_i - 1] = ft_strdup(arg[i]);
	env2[i - option_i - 1] = NULL;
	env3 = (option_i) ? env2 : ft_mix_env(env, env2);
	ret = ft_env3(p, arg, env3, i, tab_pipe_i);
	if (!option_i)
		ft_memdel((void**)&env3);
	ft_free_tab(&env2);
	return (ret);
}

int				ft_env(t_parse *p, char **arg, char **env, int tab_pipe_i)
{
	int		ret;

	ret = 0;
	if (!arg[1])
		display_env(env);
	else
		return (ft_env2(p, arg, env, tab_pipe_i));
	return (ret);
}
