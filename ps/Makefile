# Makefile for Push Swap
NAME = ../push_swap
CC = cc -Wall -Wextra -Werror

# Directories
FT_PRINTF_DIR = ft_printf

# Source files based on your directory structure
SRCS = parsing/ft_split.c \
       parsing/handle_error.c \
       parsing/parsing.c \
       parsing/utils.c \
       sort/chunks.c \
       sort/moves.c \
       sort/push_back.c \
       sort/sort_2.c \
       sort/sort.c \
       sort/stack_operations.c \
       push_swap.c

# Object files
OBJS = $(SRCS:.c=.o)

# Library files
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

# Main target
all: $(NAME)

$(NAME): $(OBJS) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(FT_PRINTF)

$(FT_PRINTF):
	@make -C $(FT_PRINTF_DIR)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re