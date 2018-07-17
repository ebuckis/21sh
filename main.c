#include "libft/includes/libft.h"
#include "edition/includes/ft_edition.h"
#include "parser/includes/ft_parser.h"

int		main()
{
	char	*string;
	t_parse *p;
	int		a;

	a = 1;
	while (a)
	{
		string = ft_edition("prompt $> ");
		dprintf(2, "________________________\nstring: %s\n", string);
		if (string)
		{
			if (ft_strcmp("exit", string) == 0)
				a = 0;
			else
			{
				p = ft_parser(string);
				dprintf(2, "________________________\nstring:\n%s\ns :\n%s\nident :\n%s\n________________________\n",string, p->s, p->ident);
			}
		}
	}
	return (0);
}
