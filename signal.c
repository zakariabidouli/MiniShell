#include "minishell.h"

void handle_int(int signo) 
{
	if (signo == SIGINT)
    {
		// rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void handle_quit(int sig_code)
{
	if (sig_code == SIGQUIT)
	{
		printf("Quit: 3\n");
	}
	else
	{
		// rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}
