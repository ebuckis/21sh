/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 15:05:42 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/07 10:14:04 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static int		rest_gnl(const int fd, char **line, char **rest_fd)
{
	if (!(*line = ft_strnew(BUFF_SIZE)))
		return (-1);
	if (rest_fd[fd] != NULL)
	{
		ft_strcpy(*line, rest_fd[fd]);
		ft_memdel((void**)&rest_fd[fd]);
	}
	if (ft_strchr(*line, '\n'))
	{
		if (!(rest_fd[fd] = ft_strnew(BUFF_SIZE)))
			return (-1);
		ft_strcpy(rest_fd[fd], ft_strchr(*line, '\n') + 1);
		*(ft_strchr(*line, '\n')) = '\0';
		return (1);
	}
	return (2);
}

static void		split_buff(char **line, char *rest_fd, char *buff)
{
	char			*delete;

	ft_strcpy(rest_fd, ft_strchr(buff, '\n') + 1);
	*(ft_strchr(buff, '\n')) = '\0';
	delete = *line;
	*line = ft_strjoin(*line, buff);
	ft_memdel((void**)&delete);
	if (buff != NULL)
		ft_memdel((void**)&buff);
}

static int		copy_buff(char **line, char *rest_fd, char *buff, int ret_read)
{
	char			*delete;

	delete = *line;
	*line = ft_strjoin(*line, buff);
	ft_memdel((void**)&delete);
	if (ret_read == 0)
	{
		if (buff != NULL)
			ft_memdel((void**)&buff);
		if (rest_fd != NULL && *line[0] == '\0')
			ft_memdel((void**)&rest_fd);
		if (*line != NULL && line[0] == '\0')
			ft_memdel((void**)line);
		return ((*line[0] == '\0') ? 0 : 1);
	}
	return (2);
}

static int		read_gnl(const int fd, char **line, char **rest_fd, char *buff)
{
	int				ret_read;
	int				ret_copy;

	ret_read = BUFF_SIZE;
	while (ft_strchr(buff, '\n') == NULL && ret_read)
	{
		ft_strclr(buff);
		if ((ret_read = read(fd, buff, BUFF_SIZE)) < 0)
			return (-1);
		if (ft_strchr(buff, '\n'))
		{
			if (!(rest_fd[fd] = ft_strnew(BUFF_SIZE)))
				return (-1);
			split_buff(line, rest_fd[fd], buff);
			return (1);
		}
		else
		{
			ret_copy = copy_buff(line, rest_fd[fd], buff, ret_read);
			if (ret_copy < 2)
				return (ret_copy);
		}
	}
	return (-1);
}

int				get_next_line(const int fd, char **line)
{
	static char		*rest_fd[4864] = {0};
	int				ret;
	char			*buff;

	if (fd >= 0 && fd < 4864 && BUFF_SIZE > 0 && line != NULL)
	{
		ret = rest_gnl(fd, line, rest_fd);
		if (ret < 2)
			return (ret);
		if (!(buff = ft_strnew(BUFF_SIZE)))
			return (-1);
		ret = read_gnl(fd, line, rest_fd, buff);
		return (ret);
	}
	return (-1);
}
