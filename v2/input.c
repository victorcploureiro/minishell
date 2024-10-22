/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:25:00 by vcarrara          #+#    #+#             */
/*   Updated: 2024/10/22 13:33:40 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

extern volatile sig_atomic_t	g_status;

int	ft_space_prompt(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_is_space(str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

void	ft_execute_aux(t_shell *shell)
{
	if (!ft_open_heredoc(shell->root, shell))
	{
		ft_clear_ast(shell->root);
		ft_freephrase(shell->parse->phrase_grammar);
		return ;
	}
	if (ft_grammar_rules(shell->parse->phrase_grammar))
	{
		ft_freephrase(shell->parse->phrase_grammar);
		ft_execution(shell->root, shell);
	}
	else
		if (shell->parse->phrase_grammar)
			ft_freephrase(shell->parse->phrase_grammar);
	ft_clear_ast(shell->root);
}

void	ft_execute(char *str, t_shell *shell)
{
	if (!str || ft_strlen(str) == 0 || ft_space_prompt(str))
		return ;
	shell->parse = malloc(sizeof(t_parse));
	shell->parse->prompt = str;
	shell->parse->split_prompt = ft_parser(shell->parse);
	shell->parse->phrase = \
		ft_construct_phrase(shell->parse->split_prompt, shell);
	shell->parse->phrase_grammar = \
		ft_construct_phrase(shell->parse->split_prompt, shell);
	shell->root = ft_ast(shell->parse->phrase);
	if (shell->root)
		ft_execute_aux(shell);
	ft_free_matrix(shell->parse->split_prompt);
	free(shell->parse);
	return ;
}

char	*ft_read_input(t_shell *shell)
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
	if (!ft_space_prompt(prompt))
		add_history(prompt);
	return (prompt);
}
