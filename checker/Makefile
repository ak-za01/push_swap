NAME = ../checker
CC = cc
CFLAGS = -Wall -Wextra -Werror


SRCS = # Add your checker source files here

# Object files
OBJS = $(SRCS:.c=.o)

# Main target
all: $(NAME)

$(NAME): $(OBJS) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c checker.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re