/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_heredoc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/20 12:06:12 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/27 17:54:46 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_parser.h"

static void	ft_replace_arg(t_parse *p, int j)
{
	int		len;
	char	*tmp;

	if (!p->hdoc[j])
		p->hdoc[j] = ft_strdup("");
	len = ft_strlen(p->hdoc[j]);
	ft_strdel(&(p->arg[p->i]));
	p->arg[p->i] = ft_strdup(p->hdoc[j]);
	tmp = ft_strnew(len);
	tmp[len] = '\0';
	while (len)
	{
		len--;
		tmp[len] = HEREDOC;
	}
	ft_strdel(&(p->arg_id[p->i]));
	p->arg_id[p->i] = tmp;
}

static int	ft_save_hdoc(t_parse *p, int j)
{
	char	*stop;
	char	*line;
	char	*tmp;

	p->i++;
	stop = p->arg[p->i];
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
	ft_replace_arg(p, j);
	p->i++;
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
	while (p->arg[p->i] && p->arg_id[p->i])
	{
		//dprintf(2, "+++++++++++on est a arg[%d] : %s\n", p->i, p->arg[p->i]);
		if (p->arg_id[p->i][0] == HEREDOC)
		{
			ft_save_hdoc(p, j);
			j++;
		}
		else
			p->i++;
	}
	return (1);
}
