/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:31:49 by vcarrara          #+#    #+#             */
/*   Updated: 2024/09/12 16:08:46 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The lexer will get the input from the prompt once the user pressed enter and create so called lexer_tokens from it
The lexer_tokens are a 2D char array char *lexer_tokens[]
Now the given input i.e. cat <<eof >file1 && cat file1 && abc || wc <file1 | cat >file2 will result in lexer_tokens like

lex_tok[0] cat
lex_tok[1] <<eof
lex_tok[2] >file1
lex_tok[3] &&
lex_tok[4] cat
lex_tok[5] file1
lex_tok[6] &&
lex_tok[7] abc
lex_tok[8] ||
lex_tok[9] wc
lex_tok[10] <file1
lex_tok[11] |
lex_tok[12] cat
lex_tok[13] >file2

*/

#include "minishell.h"
