/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vterzian <vterzian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 13:25:27 by vterzian          #+#    #+#             */
/*   Updated: 2014/12/12 17:31:21 by vterzian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_fdf_lauch(char *file, t_env *env)
{
	env->file = file;
	env->win = NULL;
	env->mlx = mlx_init();
	env->width = W_WIDTH;
	env->height = W_HEIGHT;
	env->map = ft_fdf_get_map(env->file);

	if (util->mlx != NULL)
	{
		util->win = mlx_new_window(env->mlx, env->width, env->height, "MY_FDF");
		mlx_loop(env->mlx);
	}
}
