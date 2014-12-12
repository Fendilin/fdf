/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsadd_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vterzian <vterzian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 14:48:33 by vterzian          #+#    #+#             */
/*   Updated: 2014/12/12 13:20:26 by vterzian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

s_line	ft_lsadd_end(s_line list, int *tabint, int size)
{
	s_line new_node;
	s_line tmp;

	new_node = malloc(sizeof(s_line));
	new_node->*tabint = tabint;
	new_node->size = size;
	new_node->next = NULL;
	if (list == NULL)
		return (new_node);
	tmp = list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_node;
	return (list);
}
