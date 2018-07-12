#include  "libft/includes/libft.h"
#include  "edition/includes/ft_edition.h"

int		main()
{
	char	*string;
	int		a;

	a = 1;
	while (a)
	{
		string = ft_edition("prompt $> ");
		if (ft_strcmp("exit", string) == 0)
			break ;
	}
	return (0);
}
