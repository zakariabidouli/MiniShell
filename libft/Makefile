
.PHONY: all clean fclean re

NAME 	= libft.a

CC 		= gcc
FLAGS	= -Wall -Wextra -Werror


SRC 	 =  ft_atoi.c ft_bzero.c ft_calloc.c  ft_isalpha.c ft_isdigit.c ft_itoa.c  ft_isprint.c 			\
			ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_isalnum.c		\
			ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c  ft_split.c ft_strchr.c ft_strdup.c ft_isascii.c	\
			ft_striteri.c ft_strjoin.c ft_strlcpy.c ft_strlcat.c  ft_strlen.c ft_strmapi.c ft_strnstr.c		\
			ft_strrchr.c  ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_strncmp.c 


B = 	ft_lstnew_bonus.c		\
		ft_lstadd_front_bonus.c	\
		ft_lstsize_bonus.c		\
		ft_lstlast_bonus.c		\
		ft_lstadd_back_bonus.c	\
		ft_lstdelone_bonus.c	\
		ft_lstclear_bonus.c		\
		ft_lstiter_bonus.c		\
		ft_lstmap_bonus.c

OBJS 		= $(SRC:%.c=%.o)

OBJS_B 		= $(B:%.c=%.o)
	

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS) 

$(OBJS): $(SRC)
	 $(CC) $(FLAGS) -c $(SRC) 

$(OBJS_B): $(B)
	 $(CC) $(FLAGS) -c $(B)

bonus: $(OBJS_B)
	ar -rc $(NAME) $(OBJS_B)

clean:
	rm -rf $(OBJS) $(OBJS_B)

fclean: clean
	rm -rf $(NAME)

re: fclean all

