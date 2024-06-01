/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:11:15 by dclement          #+#    #+#             */
/*   Updated: 2024/04/05 16:37:57 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H
# define FLOOR "./textures/tile.xpm"
# define PLAYER_SP "./textures/samurai.xpm"
# define PLAYER_IDLE "./textures/espera.xpm"
# define RUNNING_SP "./textures/running.xpm"
# define COLLECTABLE_SP "./textures/key_collectible.xpm"
# define EXIT_SP "./textures/closed_door.xpm"
# define EXIT2 "./textures/open_door.xpm"
# define WALL_SP "./textures/wall.xpm"
# define TILE_SIZE 32

# include <stdlib.h>
# include <stdio.h>
# include "./mlx/mlx.h"
# include "get_next_line.h"
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;

enum	e_keycodes
{
	ESC = 53,
	KEY_UP = 13,
	KEY_DOWN = 1,
	KEY_LEFT = 0,
	KEY_RIGHT = 2
};
typedef enum e_tiletype
{
	EMPTY = '0',
	WALL = '1',
	COLLECTABLE = 'C',
	PLAYER = 'P',
	EXIT = 'E'
}	t_tiletype;

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_tile
{
	t_tiletype		type;
	t_tiletype		og_type;
	t_vector		position;
	struct s_tile	*up;
	struct s_tile	*down;
	struct s_tile	*left;
	struct s_tile	*right;
}	t_tile;

typedef struct s_effect
{
	void		*img;
	t_vector	pos;
	int			frames;
	int			counter;
}	t_effect;

typedef struct s_player
{
	t_tile	*tile;
	void	*actual_img;
	void	*idle_img;
}	t_player;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_vector	win_size;
	t_tile		**tilemap;
	t_player	player;
	t_bool		**visited;
	int			flag;
	int			og_collectables;
	int			ac_collectables;
	int			num_moves;
	void		*door_open_img;
	void		*door_close_img;
	void		*key_img;
	void		*wall_img;
	void		*floor_img;
	t_vector	img_size;
}	t_game;

typedef struct s_mapcheckdata
{
	t_vector	size;
	t_vector	point;
	t_bool		v_player;
	t_bool		v_exit;
	t_bool		v_collectable;
}	t_mapcheckdata;

int		error(const char *str);
void	*null_err(const char *str);
void	free_tilemap(t_game *game);
int		end_program(t_game *game);
void	open_img(t_game *game);
int		update(t_game *game);
int		input(int key, t_game *game);
t_bool	start(t_game *game, int argc, char **argv);
void	remove_player(t_game *game);
void	move_to_empty(t_game *game, t_tile *tile);
void	pick_collectable(t_game *game, t_tile *tile);
void	move_to_exit(t_game *game);
t_tile	**tilemap_generator(char **map, t_game *game);
t_bool	is_valid_file(int argc, char **argv);
char	**map_reader(char *file);
void	open_floor_img(t_game *game);
void	open_collectible_img(t_game *game);
void	render(t_game game);
int		map_linecount(char **map);
int		is_valid_char(char c);
void	free_map(char **map);
int		is_valid_map(char **map, t_game *game);
int		is_valid_border(char c, t_vector point, t_vector size);
t_bool	initialize_flood(char **map, t_game *game);
void	free_visited(t_game *game, int i);

#endif