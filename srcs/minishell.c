/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:18:11 by vcarrara          #+#    #+#             */
/*   Updated: 2024/09/12 16:06:50 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_env	*envv;

	handle_global_signals();
	envv = init_envv(envp);
	if (envv == NULL)
	{
		printf("Error: Environment initialization failed\n");
		return (EXIT_FAILURE);
	}
	set_envp(envp);
	set_envv(envv);
	if (hide_ctrl_echo() == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (argc != 1)
		return (handle_flags(argc, argv));
	if (routine() == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	handle_flags(int argc, char *argv[])
{
	int	exit_code;

	if (argc != 3 || ft_strcmp(argv[1], "-c") != 0)
	{
		print_usage();
		return (EXIT_FAILURE);
	}
	exit_code = lexer(argv[2]);
	if (exit_code == EXIT_FAILURE)
		printf("Error: Lexer failed in handle_flags\n");
	free_envv(get_envv());
	return (exit_code);
}

static void	print_usage(void)
{
	printf("Usage: ./minishell [Flag] \"[Command]\"\n");
	printf("\t-c\tExecute Command without prompt\n");
}
