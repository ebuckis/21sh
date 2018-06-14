#include  "libft.h"

int		main()
{
	char	**arg;
	char	*line;
	int		i;

	arg = NULL;
	while (1)
	{
		i = 0;
		ft_putstr("---> ");
		get_next_line(0, &line);
		arg = ft_parser(line);
		if (ft_strcmp(line, "exit") == 0)
		{
			free(line);
			return (0);
		}
		free(line);
		
	}
	return (0);
}
