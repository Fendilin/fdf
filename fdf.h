/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vterzian <vterzian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 13:25:22 by vterzian          #+#    #+#             */
/*   Updated: 2014/12/10 14:54:28 by vterzian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "get_next_line.h"
# include <fcntl.h>

typedef struct s_line
{
	int *tabint;
	int size;

	struct s_line *next;
}	t_line;

typedef struct s_coord
{
	int	x;
	int	y;
	int z;

	struct s_coord *next;
}	t_coord
#endif
