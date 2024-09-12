/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:52:39 by vcarrara          #+#    #+#             */
/*   Updated: 2024/09/12 16:07:16 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	exit_routine(void *to_free, int exit_status)
{
	if (exit_status == EXIT_CTRL_D)
		handle_exit_ctrl_d();
	rl_clear_history();
	free(to_free);
	free_envv(get_envv());
	return (exit_status);
}

static void	handle_exit_ctrl_d(void)
{
	char	**args;

	args = ft_calloc(3, sizeof(*args));
	if (args == NULL)
	{
		printf("Error: Memory allocation failed in exit_routine\n");
		return ;
	}
	set_exit_args(args);
	exit_inbuilt(args);
	ft_free_split(args);
}

static void	set_exit_args(char **args)
{
	args[0] = ft_strdup("exit");
	if (args[0] == NULL)
	{
		printf("Error: Memory allocation failed for args[0]\n");
		ft_free_split(args);
		return ;
	}
	args[1] = ft_itoa(get_err_code());
	if (args[1] == NULL)
	{
		printf("Error: Memory allocation failed for args[1]\n");
		ft_free_split(args);
	}
}
