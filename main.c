/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vterzian <vterzian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 13:21:34 by vterzian          #+#    #+#             */
/*   Updated: 2014/12/12 19:07:35 by vterzian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_env	env;
	(void)argc;

	if (argv[1] != NULL)
	{
		ft_fdf_lauch(argv[1], &env);
	}
	int i;
	int j;
	for (j = 0; j < env.map->height; j++)
	{
		for(i = 1; i < env.map->data[j][0] + 1; i++)
		{
			ft_putnbr(env.map->data[j][i]);
			if (env.map->data[j][i] < 9)
			{
				ft_putchar(' ');
				ft_putchar(' ');
			}
			else
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
	return (0);
}
