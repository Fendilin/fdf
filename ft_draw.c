/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vterzian <vterzian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 13:23:34 by vterzian          #+#    #+#             */
/*   Updated: 2015/01/14 16:28:10 by vterzian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_y(t_env *env, t_2d *pt3d)
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;
	int y;

	x1 = pt3d->dx;
	y1 = pt3d->dy;
	y = y1;
	x2 = pt3d->x;
	y2 = pt3d->y;
	while (y >= y2)
	{
		ft_put_pixel_to_img(0xFFFFFF, env,
		x1 + ((x2 - x1) * (y - y1)) / (y2 - y1), y);
		y--;
	}
}

void	ft_draw_line(t_env *env, t_2d *pt3d)
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;
	int	x;

	x1 = pt3d->x;
	x = x1;
	y1 = pt3d->y;
	x2 = pt3d->next->x;
	y2 = pt3d->next->y;
	while (x <= x2)
	{
		ft_put_pixel_to_img(0xFFFFFF, env, x,
		y1 + ((y2 - y1) * (x - x1)) / (x2 - x1));
		x++;
	}
}

t_2d	*ft_set_iso(t_env *env, t_3d *pt3d)
{
	int		x;
	int		y;
	t_2d	*pt2d;
	t_2d	*tmp;

	y = 0;
	while (env->map->height > y)
	{
		x = 1;
		while (env->map->data[y][0] >= x)
		{
			if (x == 1 && y == 0)
			{
				pt2d = malloc(sizeof(*pt2d));
				tmp = pt2d;
			}
			else
			{
				pt2d->next = malloc(sizeof(*pt2d));
				pt2d = pt2d->next;
				pt3d = pt3d->next;
			}
			pt2d->x = CTE1 * pt3d->x - CTE2 * pt3d->y + env->startx;
			pt2d->y = pt3d->z * env->deep + (CTE1 / 2) * pt3d->x + (CTE2 / 2) * pt3d->y + env->starty;
			pt2d->dx = CTE1 * pt3d->dx - CTE2 * pt3d->dy + env->startx;
			pt2d->dy = pt3d->dz * env->deep
			+ (CTE1 / 2) * pt3d->dx + (CTE2 / 2) * pt3d->dy + env->starty;
			pt2d->next = NULL;
			x++;
		}
		y++;
	}
	return (tmp);
}

t_3d	*ft_set_3d(t_env *env)
{
	int				x;
	int				y;
	t_3d			*pt3d;
	t_3d			*tmp;

	y = 0;
	while (env->map->height > y)
	{
		x = 1;
		while (x <= env->map->data[y][0])
		{
			if (x == 1 && y == 0)
			{
				pt3d = malloc(sizeof(*pt3d));
				tmp = pt3d;
			}
			else
			{
				pt3d->next = malloc(sizeof(*pt3d));
				pt3d = pt3d->next;
			}
			pt3d->x = x * env->space;
			pt3d->y = y * env->space;
			if (y + 1 < env->map->height)
			{
				pt3d->dx = pt3d->x;
				pt3d->dy = (y + 1) * env->space;
				pt3d->dz = env->map->data[y + 1][x];
			}
			pt3d->z = env->map->data[y][x];
			pt3d->next = NULL;
			x++;
		}
		y++;
	}
	return (tmp);
}

void	ft_put_pixel_to_img(unsigned long color, t_env *env, int x, int y)
{
	int				i;
	unsigned char	col[(env->img->bpp / 8) - 1];

	i = 0;
	if (x < env->width && y < env->height && y >= 0 && x >= 0)
	{
		while (i < (env->img->bpp / 8) - 1)
		{
			col[i] = mlx_get_color_value(env->mlx, color) >> (i * 8);
			i++;
		}
		while (i >= 0)
		{
			env->img->data
			[y * env->img->sizeline + x * env->img->bpp / 8 + i] = col[i];
			i--;
		}
	}
}

void	ft_draw_data(t_env *env)
{
	t_2d	*tmp;
	t_3d	*pt3d;
	t_2d	*ptiso;

	pt3d = ft_set_3d(env);
	ptiso = ft_set_iso(env, pt3d);
	tmp = ptiso;
	env->img->data = mlx_get_data_addr(env->img->img_ptr,
	&env->img->bpp, &env->img->sizeline, &env->img->endian);
	while (tmp->next != NULL)
	{
		ft_draw_line(env, tmp);
		ft_draw_y(env, tmp);
		tmp = tmp->next;
	}
}
