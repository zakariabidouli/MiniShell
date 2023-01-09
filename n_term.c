#include "minishell.h"

t_cmd *exec(t_cmd *cmd)
{
    t_exec_c *ecmd;
    int i;

    i = 0;
    ecmd = (t_exec_c *)cmd;
    while (ecmd->args[i])
    {
        // printf(">>>>>>>> %s \n", ecmd->args[i]);
        *ecmd->end_args[i] = 0;
        i++;
    }
    return (cmd);
}

t_cmd *redir(t_cmd *cmd)
{
    t_redir_c *rcmd;

    rcmd = (t_redir_c *)cmd;
    n_term(rcmd->cmd);
    *rcmd->efile = 0;
    return (cmd);
}

t_cmd *pip(t_cmd *cmd)
{
    t_pipe_c *pcmd;

    pcmd = (t_pipe_c *)cmd;
    n_term(pcmd->left);
    n_term(pcmd->right);
    return (cmd);
}

t_cmd *list(t_cmd *cmd)
{
    t_list_c *lcmd;

    lcmd = (t_list_c *)cmd;
    n_term(lcmd->left);
    n_term(lcmd->right);
    return (cmd);
}

t_cmd *back(t_cmd *cmd)
{
    t_back_c *bcmd;

    bcmd = (t_back_c *)cmd;
    n_term(bcmd->cmd);
    return (cmd);
}
