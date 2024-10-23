/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:35:05 by vcarrara          #+#    #+#             */
/*   Updated: 2024/10/23 12:41:00 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_env_print(t_vector *vars)
{
	unsigned long	i;
	char			*full_string;

	i = 0;
	while (i < ft_vector_size(vars))
	{
		full_string = ft_strdup(ft_value(vars, i, 3));
		if (ft_strchr(full_string, '='))
		{
			ft_putendl_fd(full_string, STDOUT_FILENO);
			free(full_string);
			i++;
		}
	}
}

void	ft_builtin_env(t_shell *shell, t_vector *cmd)
{
	if (cmd->size > 1)
	{
		ft_putendl_fd("env: No args accepted", STDERR_FILENO);
		ft_status(127);
	}
	else
		ft_env_print(shell->envp_dict);
}
