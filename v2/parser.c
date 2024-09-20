/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:10:17 by vcarrara          #+#    #+#             */
/*   Updated: 2024/09/20 16:20:21 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

void	ft_prompt_ordering(t_parse *parse) // TODO: refatorar essa função
{
	int		size;
	char	*prompt_ordered;
	char	*signal;

	signal = NULL;
	size = 0;
	if (parse->prompt)
		size = ft_strlen(parse->prompt);
	prompt_ordered = malloc((size) * sizeof(char *) + 1);
	parse->idx = malloc(sizeof(t_index));
	parse->idx->i = 0;
	parse->idx->j = 0;
	while (parse->prompt[parse->idx->i] != '\0')
	{
		if (ft_strchr("\'\"", parse->prompt[parse->idx->i]))
			ft_parse_quotes(parse, prompt_ordered, signal); // TODO: implementar essa função
		if (parse->idx->i < size && ft_is_space(parse->prompt[parse->idx->i]))
			parse->prompt[parse->idx->i] = ' ';
		if (!ft_parse_char(parse, prompt_ordered))
			prompt_ordered[parse->idx->j] = parse->prompt[parse->idx->i];
		if (parse->idx->i < size)
			parse->idx->i++;
		parse->idx->j++;
	}
	prompt_ordered[parse->idx->j] = '\0';
	parse->prompt_ordered = prompt_ordered;
	free(parse->idx);
}

char	**ft_parser(t_parse *parse)
{
	char	**split;

	ft_prompt_ordering(parse);
	split = ft_split(parse->prompt_ordered, ' ');
	ft_treat_subspace(split); // TODO: implementar essa função
	free(parse->prompt_ordered);
	return (split);
}
