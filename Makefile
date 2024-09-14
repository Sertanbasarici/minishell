NAME = minishell
SRC = main.c double_quotes.c single_quotes.c parsing_token.c parsing_quotes.c parsing_special.c parsing_special_1.c util.c util_2.c init.c ft_exec.c

OBJS = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Werror -Wextra -Wall
RM = rm -rf

all: $(NAME)
$(NAME): $(OBJS)
	@$(MAKE) -C ./libft
	@$(CC) $(CFLAGS) $(OBJS) -lreadline ./libft/libft.a -o $(NAME)

clean:
	@$(MAKE) -C ./libft clean
	@$(RM) $(OBJS)

fclean:
	@$(MAKE) -C ./libft fclean
	@$(RM) $(OBJS) $(NAME)

re: fclean all

.PHONY: all re clean fclean
