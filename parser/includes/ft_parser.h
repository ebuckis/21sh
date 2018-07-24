/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parser.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/15 08:10:02 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/24 14:20:43 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H

# include "../../libft/includes/libft.h"
# include "../../edition/includes/ft_edition.h"

# define SPACE -1
# define SPECIAL '0'
# define WORD '1'
# define REDIR_FILE '2'
# define REDIR '3'
# define PIPE '4'
# define SEMICOLON '5'

// reste $var $? ~ a gerer

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
	int			ret;
}				t_parse;

/*
** s : line d'entree
** str : line parsee
** ident : meme format que str et permet d'identifier les arg
** arg : split de str
** arg_id : split de ident
*/
t_parse			*ft_parser(char *line);
int				ft_antislash(t_parse *p);
t_parse			*ft_init_parse(char *line);
int				ft_is_separator(t_parse *p);
int				ft_is_white(char c);
int				ft_parse_dquote(t_parse *p);
int				ft_parse_quote(t_parse *p);
int				ft_suite_line(t_parse *p, int i, char *prompt);
void			ft_end_while(t_parse *p, char c);
int				ft_separator(t_parse *p);
t_parse			*ft_save_struct(t_parse *parsing);
/*
** permet de garder une save de t_parse meme si on sort de la fonction
*/
int				ft_close_parse(void);
/*
** ft_close permet de free la structure t_parse
*/
void			ft_add_space(t_parse *p);

#endif
