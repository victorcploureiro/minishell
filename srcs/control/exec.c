/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:44:50 by vcarrara          #+#    #+#             */
/*   Updated: 2024/09/17 16:44:56 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
The executor does as it is called, it executes the command.
If the given command is an inbuilt, it will just run the command in the same process, if it isn't it will create a child process to run the command in.
After this is decided, the redirections of input and output are done and the command is executed.
The executor always returns the exit code of whatever it did.
*/


