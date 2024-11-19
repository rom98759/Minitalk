# 🌟 GENERAL CONFIG & FLAGS 🌟
# =============================================================================

# Variables de compilation
CC := cc
CFLAGS := -Wall -Wextra -Werror -I ../../includes

# Nom de la bibliothèque
NAME := libft.a

# Fichiers sources
SRC := ft_calloc.c \
	ft_bzero.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_atoi.c \
	ft_itoa.c \
	ft_strdup.c \
	ft_split.c \
	ft_strchr.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_strmapi.c \
	ft_substr.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_striteri.c

BONUS_SRC = ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c

SOURCES_ALL = $(SRC) $(BONUS_SRC)

# Objet compilé
OBJ := $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

# =============================================================================
# 🏗️ RULES 🏗️
# =============================================================================

# Compilation de la bibliothèque libft
all: $(NAME)

$(NAME): $(OBJ)
	@ar -rcs $@ $^
	@echo "🎉 libft.a compiled!"

# Compilation silencieuse des fichiers objets
%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

bonus: $(OBJ) $(BONUS_OBJ)
	@ar -rcs $(NAME) $(OBJ) $(BONUS_OBJ)
	@echo "🎉 Bonus libft.a compiled!"

# Nettoyage des fichiers objets
clean:
	@rm -rf $(OBJ) $(BONUS_OBJ)
	@echo "🧹 Object libft files cleaned!"

# Suppression complète des objets et de la bibliothèque
fclean: clean
	@rm -rf $(NAME)
	@echo "💥 libft.a removed!"

# Reconstruction complète
re: fclean all

# =============================================================================
# 💼 PHONY RULES 💼
# =============================================================================

.PHONY : all clean fclean re bonus
