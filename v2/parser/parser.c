/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:10:17 by vcarrara          #+#    #+#             */
/*   Updated: 2024/09/24 16:06:26 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_parse_quotes(t_parse *parse, char *prompt, char *signal)
{
	signal = "";
	if (ft_strchr("\"", parse->prompt[parse->idx->i]))
	{
		prompt[parse->idx->j++] = '\"';
		signal = "\"";
	}
	else
	{
		prompt[parse->idx->j++] = '\'';
		signal = "\'";
	}
	parse->idx->i++;
	while (!ft_strchr(signal, parse->prompt[parse->idx->i]))
	{
		if (parse->prompt[parse->idx->i] == ' ')
		{
			prompt[parse->idx->j++] = 0x1A;
			parse->idx->i++;
		}
		else
			prompt[parse->idx->j++] = parse->prompt[parse->idx->i++];
	}
}

int	ft_aux_parse_char(char *ch, t_parse *parse, char *prompt)
{
	if (ft_strncmp(ch, &parse->prompt[parse->idx->i], 2) == 0)
	{
		prompt[parse->idx->j++] = ' ';
		prompt[parse->idx->j++] = parse->prompt[parse->idx->i++];
		prompt[parse->idx->j++] = parse->prompt[parse->idx->i];
		prompt[parse->idx->j] = ' ';
		return (1);
	}
	return (0);
}

int	ft_parse_char(t_parse *parse, char *prompt)
{
	if (ft_aux_parse_char("<<", parse, prompt))
		return (1);
	else if (ft_aux_parse_char(">>", parse, prompt))
		return (1);
	else if (ft_strchr("><|", parse->prompt[parse->idx->i]))
	{
		prompt[parse->idx->j++] = ' ';
		prompt[parse->idx->j++] = parse->prompt[parse->idx->i];
		prompt[parse->idx->j] = ' ';
		return (1);
	}
	return (0);
}
void	ft_prompt_ordering(t_parse *parse) // TODO: refatorar essa função
{
	int	size;

	if (parse->prompt)
		size = ft_strlen(parse->prompt);
	else
		size = 0;
	ft_allocate(parse, size);
	ft_parse_loop(parse, parse->prompt_ordered, size);
	parse->prompt_ordered[parse->idx->j] = '\0';
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
