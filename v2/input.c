/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:25:00 by vcarrara          #+#    #+#             */
/*   Updated: 2024/10/02 16:24:46 by vcarrara         ###   ########.fr       */
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

char	*rline(t_shell *shell)
{
	char	*prompt;

	ft_status_here(PROMPT, 0);
	prompt = readline("minishell $> ");
	ft_status_here(PROMPT, 1);
	if (!prompt)
	{
		printf("exit\n");
		ft_free_shell(shell);
		exit(0);
	}
	if (!ft_prompt_spaces(prompt))
		add_history(prompt);
	return (prompt);
}
