
#include "fdf.h"

static int		ft_fdf_count_columns(char *file)
{
	int		fd;
	int		i;
	char	*str;
	char	**split;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	get_next_line(fd, &str);
	split = ft_strsplit(str, ' ');
	ft_strdel(&str);
	while (split[i] != NULL)
		i++;
	free(split);
	close(fd);
	return (i);
}

static int		ft_fdf_count_lines(char *file)
{
	int 	fd;
	int 	i;
	int		j;
	char	*str;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	j = 0;
	while ((i = get_next_line(fd, &str)) > 0)
	{
		j++;
		ft_strdel(&str);
	}
	if (i == -1)
		return(-1);
	close(fd);
	return (j);
}

static int	**ft_fdf_get_map(char *file)
{
	int		nbr_lines;
	int		nbr_columns;
	int		fd;
	char	*str;
	char	**split;
	int		**map;
	int		y;
	int		x;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	y = 0;
	x = 0;
	nbr_lines = ft_fdf_count_lines(file);
	nbr_columns = ft_fdf_count_columns(file);
	map = (int**)malloc(sizeof(int**) * nbr_lines);
	*map = (int*)malloc(sizeof(int*) * nbr_columns);
	while (y < nbr_lines)
	{
		get_next_line(fd, &str);
		split = ft_strsplit(str, ' ');
		ft_strdel(&str);
		while (x < nbr_columns)
		{
			map[y][x] = ft_atoi(split[x]);
			ft_putnbr(map[y][x]);
			ft_putstr("  ");
			free(split[x]);
			x++;
		}
		free(split);
		ft_putchar('\n');
		y++;
		x = 0;
	}
	close(fd);
	return (map);
}

int						main(int argc, char **argv)
{
	(void)argc;
	char	*file;
	int	**map;
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (argv[1] == NULL)
		return (-1);
	file = argv[1];
	map = ft_fdf_get_map(file);
	while (i < ft_fdf_count_lines(file))
	{
		while (j < ft_fdf_count_columns(file))
		{
			ft_putnbr(map[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
		j = 0;
	}
	return (0);
}
