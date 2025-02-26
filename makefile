CC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g
NAME = push_swap
SRC = handle_error.c parsing.c push_swap.c \
	  stack_operations.c ft_split.c utils.c \
	  moves.c chunks.c sort2.c sort.c
OBJ = $(SRC:.c=.o)
FT_PRINTF_DIR = ft_printf

# Library files
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	make -C $(FT_PRINTF_DIR)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(FT_PRINTF)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(FT_PRINTF_DIR) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(FT_PRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
