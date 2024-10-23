/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phrasing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:21:59 by vcarrara          #+#    #+#             */
/*   Updated: 2024/10/23 10:25:23 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_vector	*ft_phrase(char **split, t_shell *shell)
{
	t_vector	*phrase;
	int			i;
	int			*token;
	t_vector	*word;

	(void)shell;
	phrase = ft_vector_create();
	if (!phrase)
		return (NULL);
	i = 0;
	while (split[i])
	{
		word = ft_vector_create();
		ft_vector_pushback(word, ft_strdup(split[i]));
		token = malloc(sizeof(int));
		*token = ft_set_token(split[i]);
		ft_vector_pushback(word, token);
		ft_vector_pushback(word, ft_strdup(split[i]));
		ft_vector_pushback(phrase, word);
		i++;
	}
	return (phrase);
}
