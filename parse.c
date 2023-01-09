#include "minishell.h"

t_cmd   *parseredirs(t_cmd *o_cmd, char **ptr, char *end_ptr)
{
	int tok;
	char *cmd;
	char *end_cmd;

	// tok = 0;
	// printf("##### DIRS >> \n");
	while(jump(ptr, end_ptr, "<>"))
	{
		tok = init_token(ptr, end_ptr, 0, 0);
		// printf("TOKEN #### >> %d\n", tok);
		if(init_token(ptr, end_ptr, &cmd, &end_cmd) != 'a')
			terminated("missing file for redirection");
		if(tok == '<' && tok)
		{
			// INPUT REDIR
			o_cmd = redir_c(o_cmd, cmd, end_cmd, O_RDONLY, 0);
			break;
		}
		else if (tok =='>' && tok)
		{
			// REDIR OVERWRITE
			o_cmd = redir_c(o_cmd, cmd, end_cmd, O_WRONLY|O_CREAT, 1);
			break;
		}
		else if(tok == '+' && tok)
		{ 
			// APPEND REDIR
			o_cmd = redir_c(o_cmd, cmd, end_cmd, O_APPEND|O_CREAT, 1);
			break;
		}
		else if(tok == 'H' && tok)
		{
			// HEREDOC REDIR
			o_cmd = redir_c(o_cmd, cmd, end_cmd, 0, -1);     
			break;
		}
  	}
	// printf("##### DIRS >> %d\n", o_cmd->id);

  	return o_cmd;
}

t_cmd  *parseblock(char **ptr, char *end_ptr)
{
	t_cmd *cmd;

	// printf("##### BLOCK >> \n");
	if(!jump(ptr, end_ptr, "("))
		terminated("parseblock");
	init_token(ptr, end_ptr, 0, 0);
	cmd = parseline(ptr, end_ptr);
	if(!jump(ptr, end_ptr, ")"))
		terminated("syntax - missing )");
	init_token(ptr, end_ptr, 0, 0);
	cmd = parseredirs(cmd, ptr, end_ptr);
	// printf("##### BLOCK >> %d\n", cmd->id);

	return (cmd);
}

t_cmd   *parseexec(char **ptr, char *end_ptr)
{
	char *cmd;
	char *end_cmd;
	int tok;
	int ac;
	t_exec_c *e_cmd;
	t_cmd *res;

	if(jump(ptr, end_ptr, "("))
		return parseblock(ptr, end_ptr);

	res = exec_c();
	e_cmd = (t_exec_c *)res;
	ac = 0;
	res = parseredirs(res, ptr, end_ptr);
	// tok = 0;

	while(!jump(ptr, end_ptr, "|)&;"))
	{
		if((tok = init_token(ptr, end_ptr, &cmd, &end_cmd)) == 0)
			break;
		else if(tok != 'a')
			terminated("syntax");
		e_cmd->args[ac] = cmd;
		e_cmd->end_args[ac] = end_cmd;
		ac++;
		if(ac >= MAX_ARG)
			terminated("too many args");
		res = parseredirs(res, ptr, end_ptr);
	}
	e_cmd->args[ac] = 0;
	e_cmd->end_args[ac] = 0;
	// printf("##### EXEC >> %d\n", res->id);
	return res;
}


t_cmd   *parsepipe(char **ptr, char *end_ptr)
{
    t_cmd *cmd;

    // printf("##### PIPE >> \n");
    cmd = parseexec(ptr, end_ptr);
    if(jump(ptr, end_ptr, "|"))
    {
    	// printf("##### PIPE >> \n");
		init_token(ptr, end_ptr, 0, 0);
		cmd = pipe_c(cmd, parsepipe(ptr, end_ptr));
    }
	// printf("###	## PIPE >>  %d\n", cmd->id);

    return cmd;
}

t_cmd   *parseline(char **ptr, char *end_ptr)
{
	t_cmd *cmd;

	// printf("##### LINE >> \n");
	cmd = parsepipe(ptr, end_ptr);
	while(jump(ptr, end_ptr, "&"))
	{
			init_token(ptr, end_ptr, 0, 0);
			cmd = back_c(cmd);	
	}
	if(jump(ptr, end_ptr, ";"))
	{
		init_token(ptr, end_ptr, 0, 0);
		cmd = list_c(cmd, parseline(ptr, end_ptr));
	}
	// printf("##### LINE >> %d\n", cmd->id);
	return cmd;
}

t_cmd   *parsecmd(char *buf)
{
    t_cmd *cmd;
    char *e_ptr;

    e_ptr = buf + strlen(buf);
	// printf("## buf [%s] \n", e_ptr);
	// printf("## len [%lu] \n", strlen(buf));
	// printf("## end [%s] \n", e_ptr);
    cmd = parseline(&buf, e_ptr);
    jump(&buf, e_ptr, "");
    if (buf != e_ptr)
    {
		// printf("## buf [%s]\n", buf);
		// printf("## buf [%s] \n", e_ptr);
        printf("l_ovrs: [%s]\n", buf);
        terminated("syntax\n");
    }
    n_term(cmd);
	// printf("###	## CMD %d>> \n", cmd->id);
    return cmd; 
}