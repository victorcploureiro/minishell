/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:27:17 by vcarrara          #+#    #+#             */
/*   Updated: 2024/09/18 17:37:04 by vcarrara         ###   ########.fr       */
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

char	*rline(void);

#endif
