/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:48:10 by vcarrara          #+#    #+#             */
/*   Updated: 2024/09/12 16:09:52 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_UTILS_H
# define ENV_UTILS_H

typedef struct s_env
{
	char	**envp;
	char	**env_var;
	char	*pwd;
	char	*oldpwd;
}			t_env;

t_env	*init_envv(char **envp);
void	free_envv(t_env *envv);
int		reinit_env_var(t_env *envv, char **argv);
char	*get_env_var_value(t_env *envv, char *var);

void	set_envv(t_env *envv);
t_env	*get_envv(void);
char	**get_env_var(void);

#endif
