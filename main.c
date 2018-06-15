#include  "libft/libft.h"
#include  "parser/includes/ft_parser.h"

int		main()
{
	t_parse	*p;
	char	*line;
	int		i;

	while (1)
	{
		i = 0;
		ft_putstr("---> ");
		get_next_line(0, &line);
		p = ft_parser(line);
		free(line);

		if (p->arg)
		{
			while (p->arg[i])
			{
				if (ft_strcmp(p->arg[i], "exit") == 0)
				{
					ft_close_parse();
					return (0);
				}
				ft_putendl(p->arg[i]);
				ft_putendl(p->arg_id[i]);
				i++;
			}
		}
		ft_close_parse();
	}
	return (0);
}
