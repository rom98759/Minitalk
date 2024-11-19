# =============================================================================
#	🌟 GENERAL CONFIG & FLAGS 🌟
# =============================================================================

# Program for compiling C programs
CC := cc
CFLAGS := -Wall -Wextra -Werror $(INCLUDES)

NAME_SERVER := server
NAME_CLIENT := client

# =============================================================================
#	🛠️ MANDATORY PART 🛠️
# =============================================================================

SRC_SERVER := server.c server_utils.c
SRC_CLIENT := client.c

INCLUDES := -I. -Ilibft

LIBFT := ./libft/libft.a
LIBFT_PATH := ./libft

# =============================================================================
#	🏗️ RULES 🏗️
# =============================================================================

all: $(NAME_SERVER) $(NAME_CLIENT)
	@echo "🎉 All done! Time to shine! 🎉"

# Compile SERVER
$(NAME_SERVER): $(SRC_SERVER) $(LIBFT)
	@$(CC) $(CFLAGS) $(SRC_SERVER) $(LIBFT) -o $(NAME_SERVER)
	@echo "🚀 Server compiled with flying colors!"

# Compile CLIENT
$(NAME_CLIENT): $(SRC_CLIENT) $(LIBFT)
	@$(CC) $(CFLAGS) $(SRC_CLIENT) $(LIBFT) -o $(NAME_CLIENT)
	@echo "💫 Client ready for action!"

# Clean object files (*.o)
clean:
	@rm -f *.o
	@echo "🧹 Object files swept away!"

# Clean object files (*.o) and binaries
fclean: clean
	@rm -f $(NAME_SERVER) $(NAME_CLIENT)
	@echo "💥 $(NAME_SERVER) and $(NAME_CLIENT) obliterated!"

# Recompile everything
re: fclean all
	@echo "🔄 Recompiling... Give it a sec!"

# =============================================================================
#	📚 LIBFT RULES 📚
# =============================================================================

# Make libft
$(LIBFT):
	@cd $(LIBFT_PATH) && make -s bonus
	@echo "📦 libft assembled with magic spells!"

clean_libft:
	@cd $(LIBFT_PATH) && make -s clean
	@echo "🧹 libft object files tidied up!"

fclean_libft:
	@cd $(LIBFT_PATH) && make -s fclean
	@echo "💥 libft files completely wiped!"

re_libft:
	@cd $(LIBFT_PATH) && make -s re
	@echo "🔄 libft rebuilt! It's like brand new!"

# =============================================================================
#	💼 PHONY RULES 💼
# =============================================================================

.PHONY: all clean fclean re clean_libft fclean_libft re_libft
