/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main2.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/17 17:24:11 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/19 16:11:05 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "21sh.h"

/*
// transforme les *char en *wchar_t et remplace les -1 non imprimables par le 
// caractere speciale '·'
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

static int		ft_exit(int *a, int n)
{
	dprintf(2, "----------\n");
	dprintf(2, "command nb %d\n", n);
	dprintf(2, "exit\n");
	dprintf(2, "----------\n");
	*a = 0;
	return(0);
}

static void		debug_display_command(t_parse *p, int *a, char ***p_env)
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
		p->ret = ft_manage_pipe(p, begin, p_env);
		dprintf(2, "----------\n");
	}
	if (p->arg_id[i] && !ft_strcmp(p->arg[i], "exit"))
		ft_exit(a, n);
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
	char	**my_env;

	setlocale(LC_ALL, "");
	my_env = ft_getenv(argc, argv, env);
	a = 1;
	while (a)
	{
		string = ft_edition("prompt $> ");
		if (string)
		{
			p = ft_parser(string);
			debug_display_struct(p);
			debug_display_command(p, &a, &my_env);
		}
	}
	return (0);
}
