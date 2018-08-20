/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_heredoc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/20 12:06:12 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/20 16:04:06 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_parser.h"

static char	*ft_recup_s(t_parse *p)
{
	int		start;
	int		lg;

	lg = 0;
	p->i += 3;
	start = p->i;
	while (p->ident[p->i] && p->ident[p->i] != -1)
	{
		lg++;
		p->i++;
	}
	return (ft_strsub(p->str, start, lg));
}

static int	ft_save_hdoc(t_parse *p, int j)
{
	char	*stop;
	char	*line;
	char	*tmp;

	if (!(stop = ft_recup_s(p)))
		return (0);
	while (101)
	{
		line = ft_edition("heredoc > ");
		if (line && ft_strcmp(stop, line) == 0)
		{
			free(line);
			break ;
		}
		tmp = ft_strjoin(line, "\n");
		free(line);
		line = ft_strjoin(p->hdoc[j], tmp);
		if (p->hdoc[j])
			free(p->hdoc[j]);
		free(tmp);
		p->hdoc[j] = line;
	}
	free(stop);
	return (1);
}

int			ft_heredoc(t_parse *p)
{
	int		j;

	j = 0;
	p->i = 0;
	p->hdoc = (char **)malloc(sizeof(char *) * p->nb_hdoc + 1);
	while (j <= p->nb_hdoc)
	{
		p->hdoc[j] = NULL;
		j++;
	}
	j = 0;
	p->hdoc[p->nb_hdoc] = NULL;
	while (p->str[p->i] && p->ident[p->i])
	{
		if (p->ident[p->i] == HEREDOC)
		{
			ft_save_hdoc(p, j);
			j++;
		}
		else
			p->i++;
	}
	return (1);
}
