
NAME = minishell

GCC = gcc

Flag = -Werror -Wextra -Wall -g
# /usr/local/Cellar/readline/8.1.2/lib/libreadline.a

LIBFT_BINARY = libft.a 

READLINE = 	-lreadline\
			-L /usr/local/Cellar/readline/8.2.1/lib\
			-I usr/local/Cellar/readline/8.2.1/include

SRC = main.c constructor.c help_func.c parse.c n_term.c signal.c\
	env_tools.c

OBJ = $(SRC:.c=.o)

all: ${DONE} $(NAME)

$(NAME): $(OBJ) 
	${GCC} ${Flag} ${LIBFT_BINARY} ${READLINE} -o $(NAME) $(OBJ)
	@echo "#####DONE#####"

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(NAME) ${OBJ}

re: fclean all

phony: all