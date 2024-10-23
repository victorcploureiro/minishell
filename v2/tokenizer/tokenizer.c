/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:03:36 by vcarrara          #+#    #+#             */
/*   Updated: 2024/10/23 10:19:00 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_tokenize(char *str)
{
	int			n;
	const char	*tokens[8] = {"<", ">", "<<", ">>", "|", "(", ")", 0};
	int			len;

	n = 0;
	while (tokens[n])
	{
		len = ft_strlen(tokens[n]);
		if (ft_strlen(str) <= 2 && !ft_strncmp(str, tokens[n], len))
			return (1 << n);
		n++;
	}
	return (0);
}
