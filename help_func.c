#include "minishell.h"

int open_file(void)
{
	int fd;

	fd = 0;
	while ((fd = open("console", O_RDWR)) >= 0)
	{
		if (fd >= 3)
			close(fd);
		break;
	}
	return (fd);
}

int fork_protected(void)
{
	int pid;

	pid = fork();
	if (pid == -1)
		terminated("fork");
	return pid;
}

void *ft_memset(void *b, int c, size_t len)
{
	size_t i;
	char *x;

	x = (char *)b;
	i = 0;
	while (i < len)
	{
		x[i] = (char)c;
		i++;
	}
	return (b);
}

void terminated(char *s)
{
	if (s)
		printf("%s\n", s);
	exit(1);
}

char *ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	while (i > -1)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (0);
}

char **strstrip(char *str, char c)
{
	char **arr;
	int i;
	int j;
	int len;

	len = 0;
	while (str[len] != c && str[len])
		len++;
	arr = malloc(sizeof(char *) * 2);
	arr[0] = malloc(sizeof(char) * (len + 1));
	arr[0][len] = 0;
	if (str[len])
		arr[1] = malloc(sizeof(char) * (ft_strlen(str) - len));
	else
		arr[1] = NULL;
	j = -1;
	i = 0;
	while (str[++j])
	{
		if (!i && (str[j] == c))
			i++;
		arr[i][j - len * i] = str[j + i];
	}
	return (arr);
}

void safe_free(void **ptr)
{
	if (*ptr == NULL)
		return;
	free(*ptr);
	*ptr = NULL;
}