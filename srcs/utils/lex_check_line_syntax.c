/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_check_line_syntax.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:30:45 by vcarrara          #+#    #+#             */
/*   Updated: 2024/09/17 17:43:13 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	exit_on_syntax_error(void)
{
	ft_fprintf(STDERR_FILENO, "minishell: Invalid Syntax at token\n");
	set_err_code(EXIT_SYNTAX_ERROR);
	ft_free_split(get_lex_toks());
	return (EXIT_SYNTAX_ERROR);
}

static void	skip_quotes(const char *line, int *index)
{
	char	quote;

	quote = line[*index];
	if (quote == '\'' || quote == '\"')
	{
		(*index)++;
		while (line[*index] && line[*index] != quote)
			(*index)++;
	}
}

static bool	check_syntax_at_index(const char *line, int index)
{
	if (line[index] == '(')
	{
		while (index > 0 && ft_isspace(line[index]))
			index--;
		return (index >= 0 && (line[index] == '&' || line[index] == '|'));
	}
	if (line[index] == ')')
	{
		while (index > 0 && line[index] != '(')
			index--;
		return (index >= 0 && line[index] == '(');
	}
	if (line[index] == ';' || line[index] == '\\')
		return (false);
	return (true);
}

static bool	count_and_check_subshells(const char *line)
{
	int	i;
	int	open_count;
	int	close_count;

	i = 0;
	open_count = 0;
	close_count = 0;
	while (line[i])
	{
		skip_quotes(line, &i);
		if (line[i] == '(')
			open_count++;
		if (line[i] == ')')
			close_count++;
		i++;
	}
	return (open_count == close_count);
}

bool	is_valid_line_syntax(const char *line)
{
	int	i;

	i = 0;
	if (!count_and_check_subshells(line))
		return (false);
	while (line[i])
	{
		skip_quotes(line, &i);
		if (!check_syntax_at_index(line, i))
			return (false);
		i++;
	}
	return (true);
}
