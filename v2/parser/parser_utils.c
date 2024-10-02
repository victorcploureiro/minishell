/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:56:48 by vcarrara          #+#    #+#             */
/*   Updated: 2024/10/02 15:58:31 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_allocate(t_parse *parse, int size)
{
	parse->idx = malloc(sizeof(t_index));
	parse->idx->i = 0;
	parse->idx->j = 0;
	parse->prompt = malloc(sizeof(char) * size);
}

void	ft_handle_quotes(t_parse *parse, char *prompt_ordered, char *signal)
{
	if (ft_strchr("\'\"". parse->prompt[parse->idx->i]))
		ft_parse_quotes(parse, prompt_ordered, signal);
}

void	ft_parse_loop(t_parse *parse, char *prompt_ordered, int size)
{
	char	*signal;

	signal = NULL;
	while (parse->prompt[parse->idx->i] != '\0')
	{
		ft_handle_quotes(parse, prompt_ordered, signal);
		if (parse->idx->i < size && ft_is_space(parse->prompt[parse->idx->i]))
			parse->prompt[parse->idx->i] = ' ';
		if (!ft_parse_char(parse, prompt_ordered))
			prompt_ordered[parse->idx->j] = parse->prompt[parse->idx->i];
		parse->idx->i++;
		parse->idx->j++;
	}
}
