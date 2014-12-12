/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vterzian <vterzian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 13:25:27 by vterzian          #+#    #+#             */
/*   Updated: 2014/12/12 19:07:33 by vterzian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_fdf_lauch(char *file, t_env *env)
{
	env->file = file;
	env->win = NULL;
	env->width = W_WIDTH;
	env->height = W_HEIGHT;
	env->map = ft_fdf_get_map(env->file);
	return (0);
}
