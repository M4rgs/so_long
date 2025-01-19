/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 09:29:19 by hal-moug          #+#    #+#             */
/*   Updated: 2025/01/19 19:06:38 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_characters(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (++i < game->width)
		if (game->map[0][i] != '1' || game->map[game->height - 1][i] != '1')
			return (0);
	i = 0;
	while (++i < game->height)
		if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
			return (0);
	i = 0;
	while (++i < game->height)
	{
		j = 0;
		while (++j < game->width)
		{
			if (game->map[i][j] != 'C' && game->map[i][j] != 'E'
				&& game->map[i][j] != 'P'
				&& game->map[i][j] != '0' && game->map[i][j] != '1')
				return (0);
		}
	}
	return (1);
}

int	check_required(t_game *game)
{
	int		i;
	int		j;
	int		inputs[3];

	inputs[0] = 0;
	inputs[1] = 0;
	inputs[2] = 0;
	i = 0;
	while (++i < game->height)
	{
		j = 0;
		while (++j < game->width)
		{
			if (game->map[i][j] == 'C')
				inputs[0]++;
			else if (game->map[i][j] == 'E')
				inputs[1]++;
			else if (game->map[i][j] == 'P')
				inputs[2]++;
		}
	}
	if (!inputs[0] || inputs[1] != 1 || inputs[2] != 1)
		return (0);
	return (1);
}

int	valid_map_path(t_game *game, int w, int h, char c)
{
	int	up;
	int	down;
	int	left;
	int	right;

	if (game->map[h][w] == '1' || (game->map[h][w] == 'E' && 'P' == c))
		return (0);
	if (game->map[h][w] == c)
		return (1);
	game->map[h][w] = '1';
	up = valid_map_path(game, w, h - 1, c);
	down = valid_map_path(game, w, h + 1, c);
	right = valid_map_path(game, w + 1, h, c);
	left = valid_map_path(game, w - 1, h, c);
	return (up || down || left || right);
}

int	check_valid_map(t_game *game, char *file)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->height)
	{
		x = -1;
		while (++x < game->width)
		{
			if (game->map[y][x] == 'P')
			{
				if (!valid_map_path(game, x, y, 'E'))
					return (0);
				free_map(game, 0, file);
			}
			if (game->map[y][x] == 'C')
			{
				if (!valid_map_path(game, x, y, 'P'))
					return (0);
				free_map(game, 0, file);
			}
		}
	}
	return (1);
}

int	close_game(t_game *game)
{
	if (game)
		free_resources(game);
	exit(0);
	return (0);
}
