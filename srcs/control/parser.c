/*
The parser will then check for invalid syntax and create a kind of command table called parser_tokens
This is one element of the t_par_tok \*parser_tokens[]:

typedef struct s_parser_tok
{
	t_par_tok_type	type;
	t_redir_type	redir_type[5];
	char			**cmd;
	size_t			cmd_size;
	char			**in;
	size_t			in_size;
	char			**out;
	size_t			out_size;
}	t_par_tok;

So after the syntax-check the parser is able to get the command and its
arguments as well as the redirections connected to the command.
*/
