/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:23:28 by vcarrara          #+#    #+#             */
/*   Updated: 2024/10/22 13:33:55 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

volatile sig_atomic_t	g_status = 0;

void	ft_terminal_reset(int ret)
{
	static struct termios	term;

	if (!ret)
		tcgetattr(STDIN_FILENO, &term);
	else
		tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

int	main(int argc, char **argv, char **envp)
{
	t_shell		*shell;
	extern char	**environ;

	shell = malloc(sizeof(t_shell));
	if (shell == NULL)
		return (EXIT_FAILURE);
	shell->envp = environ;
	shell->str = 0;
	ft_init_signal();
	ft_envp(shell);
	ft_status(0);
	ft_terminal_reset(0);
	while (true)
	{
		ft_sigquit();
		ft_execute(ft_read_input(shell), shell);
	}
	return (0);
}
