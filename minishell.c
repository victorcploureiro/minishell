/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:18:11 by vcarrara          #+#    #+#             */
/*   Updated: 2024/09/10 16:34:09 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_env	*envv;

	handle_global_signals();
	envv = init_envv(envp);
	if (envv == NULL)
		return (EXIT_FAILURE);
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
