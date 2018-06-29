/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_edition.h                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/18 14:40:55 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/28 15:14:27 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_EDITION_H
# define FT_EDITION_H

# define KEY_CODE_DIR buf[0] == 27 && buf[1] == 91
# define KEY_CODE_UP buf[2] == 65
# define KEY_CODE_DOWN buf[2] == 66
# define KEY_CODE_RIGHT buf[2] == 67
# define KEY_CODE_LEFT buf[2] == 68
# define KEY_CODE_END buf[2] == 70
# define KEY_CODE_HOME buf[2] == 72
# define KEY_CODE_DEL buf[0] == 127

# define CHAR_AJOUT 1
# define CHAR_SUPPR 2
# define MOVE_RIGHT 3
# define MOVE_LEFT 4

# include "../../libft/includes/libft.h"
# include <curses.h>
# include <sys/ioctl.h>
# include <unistd.h>
# include <termios.h>
# include <term.h>

typedef struct		s_navig
{
	char			*s_aff;
	char			*s_save;
	int				i;
	int				x;
	int				y;
	int				x_len;
	int				y_len;
	int				x_start;
	int				y_start;
	int				x_size;
	int				y_size;
}					t_navig;
int					ft_edition(void);
int					ft_putcharint(int c);
int					ft_get_size(int *x, int *y);
int					ft_init_nav(t_navig *n);
int					ft_key_move(t_navig *n, char *buf);
void				ft_recup_pos(int *x, int *y);
void				ft_x_change(t_navig *n, int i);
struct termios		ft_default_edit(struct termios term);
int					ft_del_char(t_navig *n);
int					ft_maj_line(t_navig *n, int i);
int					ft_new_char(t_navig *n, char *buf);


#endif
