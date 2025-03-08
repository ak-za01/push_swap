# Parent Makefile
NAME = push_swap

# Main targets
all: 
	@make -C ./ps

bonus: 
	@make -C ./bonus_checker

clean:
	@make clean -C ./ps
	@make clean -C ./bonus_checker

fclean:
	@make fclean -C ./ps
	@make fclean -C ./bonus_checker

re: fclean all

.PHONY: all clean fclean re bonus