/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/24 13:56:59 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/16 18:01:39 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./exec/includes/exec.h"

/*
** transforme les *char en *wchar_t et remplace les -1 non imprimables par le
** caractere speciale '·' pour l'afficghae du debug
** a supprimer a la fin
*/

static wchar_t	*ft_strdup_wchar(char *str)
{
	wchar_t	*wstr;
	int		i;

	i = 0;
	wstr = (wchar_t *)malloc(sizeof(*wstr) * (ft_strlen(str) + 1));
	if (wstr == NULL)
		return (NULL);
	while (str[i])
	{
		wstr[i] = (str[i] == -1) ? L'·' : str[i];
		i++;
	}
	wstr[i] = '\0';
	return (wstr);
}

static void		debug_display_struct(t_parse *p)
{
	int		i;
	wchar_t *str;
	wchar_t *ident;

	dprintf(2, "----------\n");
	dprintf(2, "p->s :\t\t%s\n", p->s);
	str = ft_strdup_wchar(p->str);
	ident = ft_strdup_wchar(p->ident);
	dprintf(2, "p->str:\t\t%S\n", str);
	dprintf(2, "p->ident:\t%S\n", ident);
	i = -1;
	while (p->arg[++i])
	{
		dprintf(2, "arg[%d]:\t\t%s\n", i, p->arg[i]);
		dprintf(2, "arg_id[%d]:\t%s\n", i, p->arg_id[i]);
	}
	dprintf(2, "----------\n");
	ft_memdel((void**)&str);
	ft_memdel((void**)&ident);
}

/*
** gestion valeur retour exit
*/

static void		ft_exit(int *a, int n, char *arg)
{
	int		i;

	dprintf(2, "----------\n");
	dprintf(2, "command nb %d\n", n);
	i = 0;
	while (arg && ((i == 0 && arg[i] == '-') || ft_isdigit(arg[i])))
		i++;
	if (arg && !arg[i])
		*a = (unsigned char)ft_atoi(arg);
	else if (!arg)
		*a = 0;
	else
	{
		ft_printf("21sh: exit: %s: numeric argument required\n", arg);
		*a = 255;
	}
	dprintf(2, "exit value = %d\n", *a);
	dprintf(2, "----------\n");
}

/*
** gestion exit ou ;
*/

static void		ft_manage_semicolon_exit(t_parse *p, int *a, char ***p_env)
{
	int		i;
	int		n;
	int		begin;

	n = 0;
	i = 0;
	while (p->arg_id[i] && ft_strcmp(p->arg[i], "exit"))
	{
		begin = i;
		dprintf(2, "----------\n");
		dprintf(2, "command nb %d\n", n);
		while (p->arg_id[i] && !ft_strchr(p->arg_id[i], SEMICOLON))
		{
			dprintf(2, "arg[%d]:\t\t%s\n", i, p->arg[i]);
			dprintf(2, "arg_id[%d]:\t%s\n", i, p->arg_id[i]);
			i++;
		}
		i += (p->arg_id[i]) ? 1 : 0;
		n++;
		dprintf(2, "begin = %d\n", begin);
		ft_manage_pipe(p, begin, p_env);
	}
	if (p->arg_id[i] && !ft_strcmp(p->arg[i], "exit"))
		ft_exit(a, n, p->arg[i + 1]);
}

/*
** affichage auteurs
** affichage titre 21sh
** en boucle, edition, parsing puis execution
*/

void			main2(char *string, char **env, int *a)
{
	static int		ret = 0;
	static int		child_pid = 0;
	t_parse *p;

	if (string)
	{
		if ((p = ft_parser(string, child_pid, env, ret)))
		{
			debug_display_struct(p);
			ft_manage_semicolon_exit(p, a, &env);
		}
		ft_memdel((void**)&string);
		ret = p->ret;
		child_pid = p->child_pid;
		ft_close_parse();
	}
}

int				main(int argc, char *argv[], char *env[])
{
	char	*string;
	t_parse *p;
	int		a;
	int		begin;
	char	**my_env;

	manage_signal();
	my_env = ft_getenv(argc, argv, env);
	a = -1;
	begin = 0;
	while (a == -1)
	{
		string = (!begin++) ? ft_strdup("toilet -f bigascii12  21 sh | lolcat")
			: ft_edition("21sh $> ");
		main2(string, my_env, &a);
	}
	ft_free_tab(my_env);
	sleep(3);
	return (a);
}
