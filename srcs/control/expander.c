/*
The expander will take the parser tokens as argument.
The expander will interprete the environment variables into their corresponding value.
It also handles subshells, creates pipes and handles all the opening of input-/output-redirections and storing the correct ones in the executor tokens.
Subshells are executed by creating a child process which runs minishell without readline reading the input, but directly handing the correct, unparsed commands to it. And after the lexer is done, it will call the parser and so on.
After passing every of those parts without errors, it calls the executor in a loop and gives the executor the correct values to work with.
After a call of the executor, an error value, similar to errno, is set to the exit code of the executor.
This error value can be checked by running echo $? and is used for the && and || logic.

This is the way the data is stored in the expander tokens and handed to the executor:

typedef struct s_expander_tokens
{
	char			**cmd;
	int				in;
	int				out;
	bool			is_pipe;
}	t_exp_tok;
*/
