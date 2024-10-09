/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:27:17 by vcarrara          #+#    #+#             */
/*   Updated: 2024/10/04 16:31:09 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <curses.h> // tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs
# include <dirent.h> // opendir, readdir, closedir
# include <errno.h>  // perror
# include <fcntl.h>  // open
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h> // sigaction, sigemptyset, sigaddset, kill
# include <stdio.h>
# include <stdlib.h>    // malloc, free
# include <string.h>    // strerror
# include <sys/ioctl.h> // ioctl
# include <sys/types.h> // wait, waitpid,signal, stat, lstat, fstat, unlink
# include <sys/wait.h>
# include <termios.h>   // isatty, ttyname, tcsetattr, tcgetattr
# include <unistd.h>
# include <limits.h> //PATH_MAX

# define HERE_DOC	0
# define FORK	1
# define PROMPT	2

typedef enum e_token
{
	WORD = 0,
	REDIN = 1 << 0,
	REDOUT = 1 << 1,
	REDIRECTS = 3,
	HEREDOC = 1 << 2,
	APPEND = 1 << 3,
	REDALL = 15,
	PIPE = 1 << 4,
	ALLEXRED = 48,
	ALLEXHEREDOC = 57,
	ALL = 63,
	ALL_W_BRACKET = 511,
	EXEC = 1 << 5
}					t_token;

typedef struct s_status
{
	int	_heredoc;
	int	_fork;
	int	_prompt;
}					t_status;

typedef struct s_index
{
	int				i;
	int				j;
	int				k;
}					t_index;

typedef struct s_parse
{
	char			*prompt;
	char			*prompt_ordered;
	t_index			*idx;
	t_vector		*phrase;
	t_vector		*phrase_grammar;
}					t_parse;

typedef struct s_vector
{
	void			**values;
	unsigned long	size;
	unsigned long	capacity;
}					t_vector;

typedef struct s_node
{
	char			*str;
	char			*str_not_expanded;
	int				type;
	struct s_node	*left;
	struct s_node	*right;
	t_vector		*phrase;
	int				fd;
}					t_node;

typedef struct s_shell
{
	t_parse			*parse;
	char			**envp;
	t_vector		*envp_dict;
	t_node			*root;
	char			*path;
	char			**path_splitted;
	int				status;
	char			*str;
}					t_shell;

char			*rline(t_shell *shell);

int				ft_status_here(int where, int st);
static t_status	*ft_init_status(void);

#endif
