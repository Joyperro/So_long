CC = cc

CFLAGS = -Wall -Wextra -Werror

# LIBFT_PATH = ../libft/

# LIBFT = $(LIBFT_PATH)libft.a

SRC = ft_printf.c ft_putnbr.c ft_print_char.c ft_print_uint.c ft_print_str.c\
	ft_num_length.c ft_print_hex.c

OBJ = $(SRC:.c=.o)

INCLUDE = ft_printf.h

NAME = libftprintf.a

all:$(NAME)

# $(LIBFT):
# 	@$(MAKE) -C $(LIBFT_PATH)
$(NAME): $(OBJ)
		@ar rcs $(NAME) $(OBJ) 
		@echo "\n$(G)Ft_printf library compiled!$(DEF_COLOR)-> $(NAME)\n"

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re