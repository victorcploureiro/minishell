/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:25:00 by vcarrara          #+#    #+#             */
/*   Updated: 2024/09/18 17:36:34 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

char	*rline(void)
{
	char	*prompt;

	prompt = readline("minishell $> ");
	if (!prompt)
		exit(0);
	add_history(prompt);
	return (prompt);
}
