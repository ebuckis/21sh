/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parser.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/01 15:16:59 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/14 18:14:05 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_antislash(t_parse *p, char *s)
{
	if (s[p->i + 1] == '\0')
	{
		ft_putstr(" > ");
		s = ft_suite_line(p, s, 0);
	}
	else
	{
		p->i++;
		ft_end_while(p, s, 0);
	}
	return (s);
}

char		*ft_parse_dquote(t_parse *p, char *s)
{
	p->i++;
	while (1)
	{
		if (s[p->i] == 92)
		{
			if (s[p->i + 1] == 96 || s[p->i + 1] == '$'
				|| s[p->i + 1] == 92 || s[p->i + 1] == 34)
				p->i++;
			ft_end_while(p, s, 0);
		}
		else if (s[p->i] == 34)
		{
			p->i++;
			return (s);
		}
		else if (s[p->i] != '\0')
			ft_end_while(p, s, 0);
		else
		{
			ft_putstr("dquote> ");
			s = ft_suite_line(p, s, 1);
		}
	}
	return (s);
}

char		*ft_parse_quote(t_parse *p, char *s)
{
	p->i++;
	while (1)
	{
		if (s[p->i] == 39)
		{
			p->i++;
			return (s);
		}
		else if (s[p->i] != '\0')
		{
			ft_end_while(p, s, 0);
		}
		while (s[p->i] == '\0')
		{
			ft_putstr("quote> ");
			s = ft_suite_line(p, s, 1);
		}
	}
	return (s);
}

static int			ft_is_white(char c)
{
	if (c == ' ')
		return (1);
	else if (c == '\t')
		return (1);
	else if (c == '\n')
		return (1);
	else if (c == '\r')
		return (1);
	else if (c == '\v')
		return (1);
	return (0);
}

int			ft_is_redirection(char c)
{
	if (c == ';')
		return (1);
	else if (c == '|')
		return (1);
	else if (c == '&')
		return (1);
	else if (c == '<')
		return (1);
	else if (c == '>')
		return (1);
	else
		return (0);
}

int			ft_is_separator(t_parse *p, char *s)
{
	int		i2;
	int		j2;

	i2 = p->i;
	j2 = 0;
	if (p->str[p->j] != -1)
	{
		if (ft_is_redirection(s[i2]))
			return (1);
		else
			return (0);
	}
	else
	{
		if (ft_isdigit((int)s[i2]) && ft_is_redirection(s[i2 + 1]))
			return (1);
		else
			return (0);
	}
}

char		*ft_separator(t_parse *p, char *s)
{
	p->len += 2;
	p->str = ft_realloc(p->str, p->len);
	p->ident = ft_realloc(p->ident, p->len);
	p->str[p->j] = -1;
	p->ident[p->j] = -1;
	p->j++;
	if (s[p->i] == ';')
		ft_end_while(p, s, 2);
	else if (s[p->i] == '|')
	{
		ft_end_while(p, s, 2);
		if (s[p->i] == '|')
			ft_end_while(p, s, 2);
	}
	else if (s[p->i] == '&' && s[p->i + 1] == '&')
	{
		ft_end_while(p, s, 2);
		ft_end_while(p, s, 2);
	}
	else if ((s[p->i] == '<' || s[p->i] == '>') && s[p->i + 1] == s[p->i])
	{
		ft_end_while(p, s, 2);
		ft_end_while(p, s, 2);
	}
	else
	{
		if (ft_isdigit(s[p->i]))
			ft_end_while(p, s, 2);
		if (s[p->i] == '<' || s[p->i] == '>')
			ft_end_while(p, s, 2);
		if (s[p->i] == '<' || s[p->i] == '>')
			ft_end_while(p, s, 2);
		if (s[p->i] == '&')
			ft_end_while(p, s, 2);
		if ((s[p->i] <= '9' && s[p->i] >= '0') || s[p->i] == '-')
			ft_end_while(p, s, 2);
	}
	p->str[p->j] = -1;
	p->ident[p->j] = -1;
	p->j++;
	return (s);
}

char		*ft_str_parser(char *s, t_parse *p)
{
	while (s[p->i])
	{
		if (s[p->i] == 92)
			s = ft_antislash(p, s);
		else if (s[p->i] == 34)
			s = ft_parse_dquote(p, s);
		else if (s[p->i] == 39)
			s = ft_parse_quote(p, s);
		else if (ft_is_separator(p, s))
		{
			ft_separator(p, s);
		}
		else if (ft_is_white(s[p->i]))
		{
			p->str[p->j] = -1;//un while a mettre 
			p->ident[p->j] = -1;
			p->i++;
			p->j++;
		}
		else
			ft_end_while(p, s, 1);
	}
	ft_putendl(p->str);
	ft_putendl(p->ident);
	free(s);
	s = p->str;
//	free(p);
	return (s);
}

char		**ft_parser(char *s)
{
	char	**arg;
	char	**argident;
	char	*copy;
	t_parse	*p;

	arg = NULL;
	if (s)
	{
		p = ft_init_parse(s);
		if (!(copy = ft_strdup(s)))
			return (NULL);
		copy = ft_str_parser(copy, p);
		arg = ft_strsplit(copy, -1);
		argident = ft_strsplit(p->ident, -1);
		free(copy);
	}
	int i = 0;
	if (arg)
	{
		while (arg[i])
		{
			if (ft_strcmp(arg[i], "exit") == 0)
			{
				free(arg[i]);
				free(arg);
				free(argident[i]);
				free(argident);
				return (0);
			}
			if (!argident[i])
				ft_putendl("ERRROOOR");
			ft_putendl(arg[i]);
			ft_putendl(argident[i]);
			free(argident[i]);
			free(arg[i]);
			i++;
		}
		free(arg);
		free(argident);
	}
	return (arg);
}
