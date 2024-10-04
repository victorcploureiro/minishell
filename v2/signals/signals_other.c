/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_other.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:32:33 by vcarrara          #+#    #+#             */
/*   Updated: 2024/10/04 17:11:22 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_term_signal(int status)
{
	return (((signed char)((status & 0x7f) + 1) >> 1) > 0);
}

int	ft_term_normal(int status)
{
	return (ft_term_signal(status) == 0);
}

int	ft_exit_status(int status)
{
	return ((status >> 8) & 0xFF);
}

int	ft_term_signal(int status)
{
	return (status & 0x7F);
}

int	ft_get_retvalue(int status)
{
	if (ft_term_signal(status))
		return (ft_term_signal(status) + 128);
	return (ft_exit_status(status));
}
