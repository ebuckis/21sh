/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parser.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/15 08:10:02 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/15 14:22:16 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H

# include "../../libft/libft.h"

typedef struct	s_parse
{
	char		*s;
	char		*str;
	char		*ident;
	char		**arg;
	char		**arg_id;
	int			len;
	int			err;
	int			i;
	int			j;
}				t_parse;

t_parse			*ft_parser(char *line);
int				ft_antislash(t_parse *p);
t_parse			*ft_init_parse(char *line);
int				ft_is_separator(t_parse *p);
int				ft_is_white(char c);
int				ft_parse_dquote(t_parse *p);
int				ft_parse_quote(t_parse *p);
int				ft_suite_line(t_parse *p, int i);
void			ft_end_while(t_parse *p, int n);
int				ft_separator(t_parse *p);
t_parse			*ft_save_struct(t_parse *parsing);
int				ft_close_parse(void);
void			ft_add_space(t_parse *p);

#endif
