/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vterzian <vterzian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 15:03:54 by vterzian          #+#    #+#             */
/*   Updated: 2014/12/12 19:07:30 by vterzian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_fdf_count_line(char *file)
{
	int		nbr_lines;
	int 	fd;
	char	*line;

	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		nbr_lines++;
		ft_strdel(&line);
	}
	return (nbr_lines);
}

int		*ft_fdf_fill_map(char **split, int len)
{
	int	*line;
	int	tmp;
	int i;

	i = 1;
	line = (int*)malloc(sizeof(int*) * len + 1);
	line[0] = len;
	while (i < len + 1)
	{
		tmp = ft_atoi(split[i - 1]);
		line[i] = tmp;
		i++;
	}
	return (line);
}

t_map	*ft_fdf_get_line(t_map *map, char *line, int i)
{
	char	**split;
	int		nbr_columns;

	split = ft_strsplit(line, ' ');
	while (split[nbr_columns] != NULL)
		nbr_columns++;
	if (map->width < nbr_columns)
		map->width = nbr_columns;
	map->data[i] = ft_fdf_fill_map(split, nbr_columns);
	return (map);
}

t_map	*ft_fdf_get_map(char	*file)
{
	t_map	*map;
	char	*line;
	int		i;
	int		fd;

	i = 0;
	map = malloc(sizeof(t_map*));
	map->height = ft_fdf_count_line(file);
	map->data = (int**)malloc(sizeof(int**) * map->height);
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		map = ft_fdf_get_line(map, line, i);
		ft_strdel(&line);
		i++;
	}
	return (map);
}
