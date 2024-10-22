/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:46:43 by vcarrara          #+#    #+#             */
/*   Updated: 2024/10/22 11:24:52 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

int	ft_count_matrix(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

int	ft_count_chr(char *str, char ch)
{
	size_t	count;

	count = 0;
	if (!str)
		return (0);
	while (count < ft_strlen(str))
	{
		if (*str == ch)
			count++;
		str++;
	}
	return (count);
}

char	ft_is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}
