/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:50:20 by tamounir          #+#    #+#             */
/*   Updated: 2025/01/19 19:06:25 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	render_images(t_game *game, int y, int x)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall.img, x * S, y * S);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->collectible.img, x * S, y * S);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->exit.img, x * S, y * S);
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->player.img, x * S, y * S);
	else if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->floor.img, x * S, y * S);
}

int	render_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			render_images(game, y, x);
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			d;

	i = 0;
	d = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == d)
			return (1);
		i++;
	}
	if (s[i] == d)
	{
		return (1);
	}
	return (0);
}

void	free_map(t_game *game, int x, char *file)
{
	int	i;

	i = -1;
	if (game->map)
	{
		while (++i < game->height)
			free(game->map[i]);
		free(game->map);
	}
	if (x == 0)
		map(game, file);
	if (x == -1)
		exit(1);
}
