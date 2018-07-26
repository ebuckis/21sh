/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/24 13:56:59 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/26 18:53:37 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./exec/includes/exec.h"

/*
// transforme les *char en *wchar_t et remplace les -1 non imprimables par le 
// caractere speciale '·' pour l'afficghae du debug
// a supprimer a la fin
*/

static wchar_t *ft_strdup_wchar(char *str)
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
}

static void		ft_exit(int *a, int n, char* arg)
{
	int		i;
	ft_printf("----------\n");
	ft_printf("command nb %d\n", n);
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
	ft_printf("exit value = %d\n", *a);
	ft_printf("----------\n");
}

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
		//ft_printf("begin = %d\n", begin);
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
		dprintf(2, "----------\n");
	}
	if (p->arg_id[i] && !ft_strcmp(p->arg[i], "exit"))
		ft_exit(a, n, p->arg[i + 1]);
}

/*
// gcc main2.c libft/libft.a edition/libedition.a parser/libparser.a -ltermcap
// ./a.out 2> /dev/ttys001
*/

int				main(int argc, char *argv[], char *env[])
{
	char	*string;
	t_parse *p;
	int		a;
	int		begin;
	char	**my_env;

	manage_signal();
	setlocale(LC_ALL, "");
	ft_printf("%C kcabus\n%C bpajot\n", L'©', L'©');
	my_env = ft_getenv(argc, argv, env);
	a = -1;
	begin = 1;
	while (a == -1)
	{
		string = (begin) ? ft_strdup("toilet -f bigascii12  21 sh | lolcat") :
			ft_edition("prompt $> ");
		begin = 0;
		if (string)
		{
			p = ft_parser(string, (p) ? p->child_pid : 0);
			ft_memdel((void**)&string);
			debug_display_struct(p);
			ft_manage_semicolon_exit(p, &a, &my_env);
		}
		else
			p->ret = 0;
		//ft_close_parse(); a mettre quand on aura recup le pid
	}
	return (a);
}
