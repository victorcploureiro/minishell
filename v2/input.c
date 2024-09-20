/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:25:00 by vcarrara          #+#    #+#             */
/*   Updated: 2024/09/20 15:53:30 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

void	ft_execute(char *str, t_shell *shell)
{
	t_parse	*parse;
	char	**split_prompt;
	t_node	*root;

	if (!str)
		return ;
	parse = malloc(sizeof(t_parse));
	if (!parse)
		return ;
	parse->prompt = str;
	split_prompt = ft_parser(parse);
}

char	*rline(void)
{
	char	*prompt;

	prompt = readline("minishell $> ");
	if (!prompt)
		exit(0);
	add_history(prompt);
	return (prompt);
}
