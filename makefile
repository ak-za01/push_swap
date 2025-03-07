# Parent Makefile
NAME = push_swap

# Main targets
all: 
	@make -C ./ps

bonus: 
	@make -C ./checker

clean:
	@make clean -C ./ps
#	@make clean -C ./$(BONUS_DIR)

fclean:
	@make fclean -C ./ps
#	@make fclean -C ./$(BONUS_DIR)

re: fclean all

.PHONY: all clean fclean re bonus