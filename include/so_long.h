/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:53:26 by hal-moug          #+#    #+#             */
/*   Updated: 2025/01/19 18:48:50 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../src/get_next_line/get_next_line.h"
# include "../src/ft_printf/ft_printf.h"
# include "../mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define S 50

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
}	t_img;

# define UP 65362
# define DOWN 65364
# define RIGHT 65363
# define LEFT 65361

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	char	**map;
	t_img	wall;
	t_img	collectible;
	t_img	exit;
	t_img	player;
	t_img	floor;
	int		player_x;
	int		player_y;
	int		collectables;
	int		moves;
}	t_game;

void	map(t_game *game, char *map_file);
int		render_map(t_game *game);
void	init_game(t_game *game, char *file);
void	shapes(t_game *game);
int		handle_input(int key, t_game *game);
int		close_game(t_game *game);
void	free_resources(t_game *game);
int		check_characters(t_game *game);
int		ft_strchr(const char *s, int c);
int		check_required(t_game *game);
int		valid_map_path(t_game *game, int w, int h, char c);
int		check_valid_map(t_game *game, char *file);
void	free_map(t_game *game, int x, char *file);
#endif
