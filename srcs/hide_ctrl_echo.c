/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hide_ctrl_echo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:52:55 by vcarrara          #+#    #+#             */
/*   Updated: 2024/09/12 16:07:50 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	hide_ctrl_echo(void)
{
	t_exp_tok	*stty_tok;

	stty_tok = malloc(sizeof(*stty_tok));
	if (stty_tok == NULL)
		return (handle_stty_error(NULL));
	stty_tok->cmd = ft_calloc(3, sizeof(*stty_tok->cmd));
	if (stty_tok->cmd == NULL)
		return (handle_stty_error(stty_tok));
	set_stty_cmd(stty_tok);
	return (execute_stty(stty_tok));
}

static void	set_stty_cmd(t_exp_tok *stty_tok)
{
	stty_tok->cmd[0] = ft_strdup("/bin/stty");
	stty_tok->cmd[1] = ft_strdup("-echoctl");
	stty_tok->in = STDIN_FILENO;
	stty_tok->out = STDOUT_FILENO;
}

static int	handle_stty_error(t_exp_tok *stty_tok)
{
	if (stty_tok != NULL)
		free(stty_tok);
	printf("Error: Memory allocation failed in hide_ctrl_echo\n");
	return (EXIT_FAILURE);
}

static int	execute_stty(t_exp_tok *stty_tok)
{
	if (executor(stty_tok) == EXIT_FAILURE)
	{
		printf("Error: Executor failed in hide_ctrl_echo\n");
		ft_free_split(stty_tok->cmd);
		free(stty_tok);
		return (EXIT_FAILURE);
	}
	ft_free_split(stty_tok->cmd);
	free(stty_tok);
	return (EXIT_SUCCESS);
}
