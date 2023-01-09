#include "minishell.h"

void update_shell(t_env *env)
{
	char *tmp;

	if (!env->envlist)
		return;
	while (env->envlist->next && !ft_strncmp(env->envlist->name, "SHLVL", 5))
		env->envlist = env->envlist->next;
	if (ft_strncmp(env->envlist->name, "SHLVL", 5))
	{
		tmp = ft_itoa(ft_atoi(env->envlist->content) + 1);
		safe_free((void **)&env->envlist->content);
		env->envlist->content = tmp;
	}
	while (env->envlist->prev)
		env->envlist = env->envlist->prev;
}

t_envlist *init_env_node(char *str)
{
	t_envlist *env;
	char **tmp;

	env = malloc(sizeof(t_envlist));
	tmp = strstrip(str, '=');
	env->name = tmp[0];
	// printf("name ###########///[ %s]\n", env->name);
	env->content = tmp[1];
	// printf("content>>>>>>/// [ %s ]\n", env->content);
	safe_free((void **)&tmp);
	return (env);
}

void to_list(char **arr, t_envlist **env_node)
{
	int i;
	t_envlist *start;

	*env_node = init_env_node("?=0");
	start = *env_node;
	(*env_node)->prev = 0;
	(*env_node)->next = 0;
	if (!arr || !arr[0])
		return;
	i = -1;
	while (arr[++i])
	{
		(*env_node)->next = init_env_node(arr[i]);
		(*env_node)->next->prev = *env_node;
		(*env_node)->next->next = 0;
		*env_node = (*env_node)->next;
	}
	*env_node = start;
}

void init_env(t_env *env, int ac, char **av, char **env_var)
{
	(void)ac;
	(void)av;
	env->env_var = env_var;
	to_list(env_var, &env->envlist);
	update_shell(env);
	// printf("\nInitial##### DONE\n");
	// env->cmd = NULL;
	env->cmd_count = 0;
	env->cwd = getcwd(0, 0);
	env->exit = 0;
}