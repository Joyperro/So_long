CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

INCLUDES = -I/opt/X11/include -I./mlx -I./libft -I./ft_printf -I.

LIBFT_PATH = ./libft/

LIBFT = $(LIBFT_PATH)libft.a

FT_PRINTF_PATH = ./ft_printf/

FT_PRINTF = $(FT_PRINTF_PATH)libftprintf.a

GNL = get_next_line.h

MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

MLX_DIR = ./mlx

MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a

SRC = main.c end_program.c error_handling.c game_input.c\
	game_start.c map_border_check.c map_check.c\
	map_datacheck.c map_parse.c open_img.c player_movement.c\
	render.c tilemap_generator.c update.c open_collect.c\
	get_next_line.c get_next_line_utils.c flood_fill.c\

OBJ = $(SRC:.c=.o)

BONUS_SRC = bonus/main.c bonus/end_program.c bonus/error_handling.c bonus/game_input.c\
    bonus/game_start.c bonus/map_border_check.c bonus/map_check.c\
    bonus/map_datacheck.c bonus/map_parse.c bonus/open_img.c bonus/player_movement.c\
    bonus/render.c bonus/tilemap_generator.c bonus/update.c bonus/open_collect.c\
    bonus/get_next_line.c bonus/get_next_line_utils.c bonus/flood_fill.c\

BONUS_OBJ = $(BONUS_SRC:.c=.o)

NAME = so_long.a

NAME_BONUS = so_long_bonus.a

EXEC_NAME = so_long

EXEC_NAME_BONUS = so_long_bonus

all: $(LIBFT) $(FT_PRINTF) $(MLX_LIB) $(NAME) $(EXEC_NAME)

bonus: $(BONUS_OBJ)
	$(CC) $(CFLAGS) -o $(EXEC_NAME_BONUS) $(BONUS_OBJ) $(LIBFT) $(FT_PRINTF) $(MLX_FLAGS)
.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)
$(FT_PRINTF):
	@$(MAKE) -C $(FT_PRINTF_PATH)
$(NAME): $(OBJ)
		@cp $(LIBFT) $(NAME)
		@cp $(FT_PRINTF) $(NAME)
		@ar rcs $(NAME) $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) $(GNL) $(MLX_FLAGS)
		@echo "\n$(G)So_long library compiled!$(DEF_COLOR)-> $(NAME)\n"
$(MLX_LIB):
	@$(MAKE) -C $(MLX_DIR)
$(EXEC_NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBFT) $(FT_PRINTF) $(MLX_FLAGS)
	@echo "\n$(G)So_long executable compiled!$(DEF_COLOR)-> so_long\n"
clean:
	@$(MAKE) -C $(MLX_DIR) clean
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) -C $(FT_PRINTF_PATH) clean
	@rm -f $(OBJ)
	@rm -f $(BONUS_OBJ)
fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(MAKE) -C $(FT_PRINTF_PATH) fclean
	@rm -f $(NAME) $(EXEC_NAME)
	@rm -f $(NAME_BONUS) $(EXEC_NAME_BONUS)
re: fclean all

.PHONY: all clean fclean re