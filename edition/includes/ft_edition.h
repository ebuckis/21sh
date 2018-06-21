/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_edition.h                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/18 14:40:55 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/21 17:22:19 by kcabus      ###    #+. /#+    ###.fr     */
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
# define KEY_CODE_DEL 127


# include "../../libft/includes/libft.h"
# include <curses.h>
# include <sys/ioctl.h>
# include <unistd.h>
# include <termios.h>
# include <term.h>

int					ft_edition(void);
struct termios		ft_default_edit(struct termios term);

typedef struct		s_navig
{
	int				x;
	int				y;
	int				x_start;
	int				y_start;
	int				x_size;
	int				y_size;
}					t_navig;

#endif
