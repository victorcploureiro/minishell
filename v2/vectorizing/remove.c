/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:10:12 by vcarrara          #+#    #+#             */
/*   Updated: 2024/10/23 11:39:42 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_vector_erase(t_vector *vector, unsigned long position)
{
	unsigned long	i;

	if (vector == NULL)
		return ;
	if (position >= vector->size)
		return ;
	i = position;
	while (i < vector->size - 1)
	{
		vector->values[i] = vector->values[i + 1];
		++i;
	}
	vector->size--;
}

void	ft_vector_popback(t_vector *vector)
{
	if (vector == NULL)
		return ;
	if (ft_vector_empty(vector))
		return ;
	ft_vector_erase(vector, vector->size - 1);
}
