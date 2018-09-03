/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_heredoc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/20 12:06:12 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/09/03 11:10:25 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_parser.h"

static int	ft_replace_ctrld(t_parse *p, char **line)
{
	ft_strdel(line);
	ft_strdel(&(p->arg[p->i]));
	p->arg[p->i] = ft_strnew(0);
	p->arg[p->i][0] = '\0';
	ft_strdel(&(p->arg_id[p->i]));
	p->arg_id[p->i] = ft_strnew(0);
	p->arg_id[p->i][0] = '\0';
	return (1);
}

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
		if (g_nav.err == SIG_CTRLD)
			return (ft_replace_ctrld(p, &line));
		if (line && ft_strcmp(stop, line) == 0)
		{
			ft_strdel(&line);
			break ;
		}
		tmp = ft_strjoin_del(line, "\n");
		line = ft_strjoin(p->hdoc[j], tmp);
		if (p->hdoc[j])
			free(p->hdoc[j]);
		ft_strdel(&tmp);
		p->hdoc[j] = line;
	}
	ft_replace_arg(p, j);
	return (1);
}

int			ft_heredoc(t_parse *p)
{
	int		j;

	j = 0;
	p->i = 0;
	p->hdoc = (char **)malloc(sizeof(char *) * (p->nb_hdoc + 1));
	while (j <= p->nb_hdoc)
	{
		p->hdoc[j] = NULL;
		j++;
	}
	j = 0;
	p->hdoc[p->nb_hdoc] = NULL;
	while (p->arg[p->i] && p->arg_id[p->i])
	{
		if (p->arg_id[p->i][0] == HEREDOC)
		{
			ft_save_hdoc(p, j);
			j++;
		}
		p->i++;
	}
	return (1);
}
