#include "minishell.h"

int jump(char **ptr, char *end_ptr, char *mark)
{
    char *tmp;

    tmp = *ptr;
    // printf("JUMP <<< [%s]\n", tmp);
    while (tmp < end_ptr && ft_strchr(SPACE, *tmp))
        tmp++;
    *ptr = tmp;
    // printf("JUMP >>>> [%s]\n", tmp);
    return (*tmp && ft_strchr(mark, *tmp));
}

t_cmd *n_term(t_cmd *cmd)
{
    // printf("<<<<<<< NTERM %d>>>>\n", cmd->id);
    if (cmd == 0)
        return 0;
    if (cmd)
    {
        if (cmd->id == EXEC_ID)
            cmd = exec(cmd);
        else if (cmd->id == PIPE_ID)
            cmd = pip(cmd);
        else if (cmd->id == LIST_ID)
            cmd = list(cmd);
        else if (cmd->id == BACK_ID)
            cmd = back(cmd);
        else if (cmd->id == REDIR_ID)
            cmd = redir(cmd);
    }
    return (cmd);
}

int init_token(char **ps, char *end_s, char **q, char **eq)
{
    char *s;
    int ret;

    s = *ps;
    while (s < end_s && ft_strchr(SPACE, *s))
        s++;
    if (q)
        *q = s;
    ret = *s;
    if (*s)
        s = switch_token(s, end_s, &ret);
    if (eq)
        *eq = s;
    while (s < end_s && ft_strchr(SPACE, *s))
        s++;
    *ps = s;
    printf("  TOKEN >>>>>> [%c]\n", (char)ret);
    return ret;
}

char *switch_token(char *s, char *es, int *ret)
{
    if (*s)
    {
        // printf("SWITCH TOKEN \n");
        if (ft_strchr(SYMBOL, *s))
            s++;
        
        else if (*s == '>')
        {
            s++;
            if (*s == '>')
            {
                *ret = '+';
                s++;
            }
        }
        else if (*s == '<')
        {
            s++;
            if (*s == '<')
            {
                *ret = 'H';
                s++;
            }
        }
        else
        {
            *ret = 'a';
            while (s < es && !ft_strchr(SPACE, *s) && !ft_strchr(SYMBOL, *s))
                s++;
        }
    }
    return s;
}

void print_cmd(t_cmd *cmd)
{
    int i = -1;
    t_back_c *bcmd;
    t_exec_c *ecmd;
    t_list_c *lcmd;
    t_pipe_c *pcmd;
    t_redir_c *rcmd;

    // cmd = inf->cmd;
    if (cmd == 0)
        exit(0);
    // cmd = *tmp;
    switch (cmd->id)
    {
    default:
        terminated("printcmd\n");

    case EXEC_ID:
        // printf("<< printing >>\n");
        ecmd = (t_exec_c *)cmd;
        // if(ecmd->args[0] == 0)
        //   exit();
        // exec(ecmd->argv[0], ecmd->argv);
        printf("<<<< >>>EXEC \n");
        while (ecmd->args[i++])
        {
            printf(" EXEC ARGs [%s] \n", ecmd->args[i]);
            // printf("exec EXEC [%s] \n", ecmd->end_args[i]);
        }
        // fflush(0);
        break;

    case REDIR_ID:
        rcmd = (t_redir_c *)cmd;
        printf("<<<<<< R >>>>>>>>\n");
        printf("CMD >>>>>>>> [%d]\n", rcmd->cmd->id);
        printf("FILE >>>>>>>> [%s]\n", rcmd->file);
        printf("FD >>>>>>>> [%d]\n", rcmd->fd);
        printf("Flag >>>>>>>> [%d]\n", rcmd->flag);

        // fflush(0);
        // if(fork_protected() == 0)
        print_cmd(rcmd->cmd);
        break;

    case LIST_ID:
        lcmd = (t_list_c *)cmd;
        printf("<<<< LIST >>\n");
        printf("<<left : [%d] >>", lcmd->left->id);
        printf("            <<right : [%d] >>\n", lcmd->right->id);
        // fflush(0);
        // if(fork_protected() == 0)
        // if(fork_protected() == 0)
        print_cmd(lcmd->left);
        print_cmd(lcmd->right);
        break;

    case PIPE_ID:
        pcmd = (t_pipe_c *)cmd;
        printf("<<<< P >>\n");
        printf("<< left : [%d] >>", pcmd->left->id);
        printf("            <<right : [%d] >>\n", pcmd->right->id);
        // fflush(stdout);
        // if(fork_protected() == 0)
        // if(fork_protec÷ted() == 0)
        print_cmd(pcmd->left);
        print_cmd(pcmd->right);
        break;

    case BACK_ID:
        bcmd = (t_back_c *)cmd;
        printf("<<<< B >>>>\n");
        printf("<< back : [%d] >>\n", bcmd->cmd->id);

        // fflush(2);
        // if(fork_protected() == 0)
        print_cmd(bcmd->cmd);
        break;
    }
}

int main(int ac, char **av, char **env)
{
    char *buf;
    int stat_loc;
    int fd;
    t_env env_inf;
    t_cmd *cmd;

    fd = open_file();
    init_env(&env_inf, ac, av, env);
    signal(SIGINT, handle_int);
    signal(SIGQUIT, handle_quit);
    // buf = env_inf.line;
    while ((buf = readline("$> ")) && buf)
    {
        // readline history
        add_history(buf);
        // if (buf[0] == 'c' && buf[1] == 'd' && buf[2] == ' ')
        // {
        //     // Chdir must be called by the parent, not the child.
        //     buf[strlen(buf)] = 0; // chop \n
        //     if (chdir((buf + 3)) < 0)
        //         printf("cannot cd %s\n", (buf + 3));
        //     // printf("%s\n", getcwd(s, 100));
        //     continue;
        // }
        if (fork_protected() == 0)
            cmd = parsecmd(buf);
        else
            wait(NULL);
        print_cmd(cmd);
    }
    exit(1);
}