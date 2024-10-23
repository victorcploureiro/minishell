/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:46:43 by vcarrara          #+#    #+#             */
/*   Updated: 2024/10/23 11:54:46 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_vector	*ft_vector_slice(t_vector *vector, unsigned long pos)
{
	unsigned long	i;
	int				j;
	t_vector		*sliced;

	if (vector == NULL || pos >= vector->size)
		return ((t_vector *)0);
	sliced = ft_vector_create();
	i = vector->size;
	pos++;
	j = 0;
	while (pos < i)
	{
		ft_vector_pushback(sliced, vector->values[pos]);
		pos++;
		j++;
	}
	j--;
	while (j >= 0)
	{
		ft_vector_popback(vector);
		j--;
	}
	return (sliced);
}
