
#include "fdf.h"

static int	ft_count_lines(char	*file)
{
	char	*str;
	int		i;
	int		j;
	int		fd;

	fd = open(file, O_RDONLY);
	while ((i = get_next_line(fd, &str)) > 0)
	{
		j++;
		ft_strdel(&str);
	}
	if (i == -1)
		return (-1);
	close(fd);
	return (j);
}

static char	**ft_get_map(int fd, int nbrlines)
{
	char		*str;
	int			i;
	int			n;
	char 		**ret;

	n = 0;
	ret = (char**)malloc(sizeof(char**) * nbrlines + 1);
	if (ret == NULL)
		return (NULL);
	while ((i = get_next_line(fd, &str)) > 0)
	{
		ret[n++] = ft_strdup(str);
		if (ret[n] == NULL)
			return (NULL);
		ft_strdel(&str);
	}
	ret[nbrlines] = NULL;
	return (ret);
}

int	main(int argc, char **argv)
{
	(void)argc;
	int 	fd;
	int		nbrlines;
	char 	**map;
	
	nbrlines = ft_count_lines(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (-1);
	map = ft_get_map(fd, nbrlines);
	while (*map)
	{
		ft_putendl(*map++);
	}
	close(fd);
	return (0);
}
