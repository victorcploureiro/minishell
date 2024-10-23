/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:46:33 by vcarrara          #+#    #+#             */
/*   Updated: 2024/10/23 11:52:41 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	*ft_value(const t_vector *vector, unsigned long i, unsigned long j)
{
	t_vector	*inner_vector;

	if (vector == NULL)
		return (0);
	if (i >= vector->size)
		return (0);
	inner_vector = vector->values[i];
	if (inner_vector == NULL)
		return (0);
	if (j >= inner_vector->size)
		return (0);
	return (inner_vector->values[j]);
}

void	*ft_vector_pos(const t_vector *vector, unsigned long index)
{
	if (vector == NULL)
		return (0);
	if (index >= vector->size)
		return (0);
	return (vector->values[index]);
}

int	ft_value_int(const t_vector *vector, unsigned long i, unsigned long j)
{
	return (*(int *)ft_value(vector, i, j));
}

bool	ft_vector_empty(const t_vector *vector)
{
	if (vector == NULL)
		return (true);
	return (vector->size == 0);
}

unsigned long	ft_vector_size(const t_vector *vector)
{
	if (vector == NULL)
		return (-1);
	return (vector->size);
}
