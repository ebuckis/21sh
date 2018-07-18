/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main2.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/17 17:24:11 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/18 11:59:48 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "edition/includes/ft_edition.h"
#include "parser/includes/ft_parser.h"
#include <locale.h>

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

static void		debug_display(t_parse *p)
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

/*
// gcc main2.c libft/libft.a edition/libedition.a parser/libparser.a -ltermcap
// ./a.out 2> /dev/ttys001
*/

int				main()
{
	char	*string;
	t_parse *p;
	int		a;
	int		i;
	int		n;

	setlocale(LC_ALL, "");
	a = 1;
	while (a)
	{
		string = ft_edition("prompt $> ");
		if (string)
		{
			p = ft_parser(string);
			debug_display(p);
			n = 0;
			i = 0;
			while (p->arg_id[i] && ft_strcmp(p->arg[i], "exit"))
			{
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
				dprintf(2, "----------\n");
			}
			if (p->arg_id[i] && !ft_strcmp(p->arg[i], "exit"))
			{
				dprintf(2, "----------\n");
				dprintf(2, "command nb %d\n", n);
				dprintf(2, "exit\n");
				dprintf(2, "----------\n");
				a = 0;
			}
		}
	}
	return (0);
}
