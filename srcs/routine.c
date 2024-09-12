/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:52:02 by vcarrara          #+#    #+#             */
/*   Updated: 2024/09/12 16:08:01 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	routine(void)
{
	char	*buf;
	int		exit_code;

	while (true)
	{
		buf = readline("minishell$ ");
		if (buf == NULL)
		{
			printf("Error: readline returned NULL\n");
			return (exit_routine((void *)buf, EXIT_CTRL_D));
		}
		handle_input(buf, &exit_code);
		if (exit_code == EXIT_FAILURE)
			return (exit_routine((void *)buf, EXIT_FAILURE));
		free(buf);
	}
	return (exit_routine((void *)buf, EXIT_FAILURE));
}

static void	handle_input(char *buf, int *exit_code)
{
	if (ft_strlen(buf) > 0)
		add_history(buf);
	*exit_code = lexer(buf);
	if (*exit_code == EXIT_FAILURE)
		printf("Error: Lexer failed in routine\n");
}
