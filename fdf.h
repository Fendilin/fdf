/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vterzian <vterzian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 13:25:22 by vterzian          #+#    #+#             */
/*   Updated: 2014/12/12 17:31:18 by vterzian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include "get_next_line.h"

# define	W_WIDTH = 1900
# define	W_HEIGHT = 1500
# define	SPACE = 25

typedef struct	s_map
{
	int	width;
	int	height;
	int	**data;
}		t_map;

typedef struct	s_env
{
	char	*file;
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	t_map	*map;
}			t_env;

int		ft_fdf_lauch(char *file, t_env *env);
t_map	ft_fdf_get_map(char *file);
t_map	ft_fdf_get_line(t_map map, char *line, int i);
int		*ft_fdf_fill_map(char **split, int len);
int		ft_fdf_count_line(char *file);

#endif
