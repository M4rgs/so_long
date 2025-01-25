/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:50:30 by tamounir          #+#    #+#             */
/*   Updated: 2025/01/25 05:01:40 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_game_helper(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	shapes(game);
	game->moves = 0;
	game->collectables = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'C')
			{
				game->collectables++;
			}
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
			}
			x++;
		}
		y++;
	}
}

void	check_map(t_game *game, char *file)
{
	if (!check_characters(game))
	{
		ft_printf("Error\nBoundary not 1 or having intruder character\n");
		free_map(game, -1, file);
	}
	else if (!check_required(game))
	{
		ft_printf("Error\nThe map must contain 1 exit, at least 1 collectible, and 1 starting\
		 position to be valid\n");
		free_map(game, -1, file);
	}
	else if (!check_valid_map(game, file))
	{
		ft_printf("Error\nno valid path\n");
		free_map(game, -1, file);
	}
}

void	init_game(t_game *game, char *file)
{
	map(game, file);
	check_map(game, file);
	free_map(game, 0, file);
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Error\nFailed MLX initialize\n");
		free_map(game, -1, file);
		exit(1);
	}
	game->win = mlx_new_window(game->mlx, game->width * S,
			game->height * S, "so long");
	if (!game->win)
	{
		if (game->mlx)
		{
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
		ft_printf("Error\nFailed loading window\n");
		free_map(game, -1, file);
	}
	init_game_helper(game);
}

void	shapes(t_game *game)
{
	game->wall.img = mlx_xpm_file_to_image(game->mlx,
			"xpm/wall.xpm", &game->wall.width, &game->wall.height);
	game->collectible.img = mlx_xpm_file_to_image(game->mlx,
			"xpm/collectible.xpm", &game->collectible.width,
			&game->collectible.height);
	game->exit.img = mlx_xpm_file_to_image(game->mlx, "xpm/exit.xpm",
			&game->exit.width, &game->exit.height);
	game->player.img = mlx_xpm_file_to_image(game->mlx,
			"xpm/player.xpm", &game->player.width, &game->player.height);
	game->floor.img = mlx_xpm_file_to_image(game->mlx,
			"xpm/floor.xpm", &game->floor.width, &game->floor.height);
	if (!game->wall.img || !game->collectible.img || !game->exit.img
		|| !game->player.img || !game->floor.img)
	{
		ft_printf("Error: loading textures\n");
		free_resources(game);
		exit(1);
	}
}

int	main(int argc, char **av)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Error, No map selected\nUsage: ");
		ft_printf("%s", av[0]);
		ft_printf(" <map_file.ber>\n");
		return (1);
	}
	init_game(&game, av[1]);
	ft_check_map_size(&game);
	mlx_key_hook(game.win, handle_input, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop_hook(game.mlx, render_map, &game);
	mlx_loop(game.mlx);
	return (0);
}
