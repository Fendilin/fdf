/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vterzian <vterzian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 13:21:34 by vterzian          #+#    #+#             */
/*   Updated: 2015/01/12 20:45:56 by vterzian         ###   ########.fr       */
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
	return (0);
}
