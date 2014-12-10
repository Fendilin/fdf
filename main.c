/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vterzian <vterzian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 13:25:27 by vterzian          #+#    #+#             */
/*   Updated: 2014/12/10 19:41:28 by vterzian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_fdf_count_lines(fd)
{
	int		i;
	char	*str;

	while ((i = get_next_line(fd, &str)) > 0)
	{
		
	}
}

static s_line 	ft_fdf_get_map(int fd)
{
	char	*str;
	int		*tab;
	int		nbr_lines;
	s_line	tab;
	
	tab = NULL;
	map = ft_fdf_get_line(str);
	while ()
	{

	}
	return (tab);
}

int				main(int argc, char **argv)
{
	(void)argc;
	s_line line;
	
	line = NULL;
	if (argv[1] == NULL)
		return (-1);
	fd = open(argv[1]);
	if (fd < 0)
		return (-1);
	line.tabint = ft_fdf_get_map(fd);
	return (0);
}
