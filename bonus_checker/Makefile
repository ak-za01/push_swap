NAME = ../checker
CC = cc
CFLAGS = -Wall -Wextra -Werror


SRCS =	GNL/get_next_line_bonus.c GNL/get_next_line_utils_bonus.c \
		parsing/ft_split_bonus.c parsing/handle_error_bonus.c \
		parsing/moves_bonus.c parsing/moves2_bonus.c \
		parsing/parsing_bonus.c parsing/stack_opps_bonus.c \
		parsing/utils_bonus.c utils_bonus.c \
		checker_bonus.c

# Object files
OBJS = $(SRCS:.c=.o)

# Main target
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c checker_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re