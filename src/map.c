/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:50:24 by tamounir          #+#    #+#             */
/*   Updated: 2025/01/25 05:00:19 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_width(char *line, int *w, int *temp, int fd)
	{
	*w = ft_strlen(line);
	if (ft_strchr(line, '\n'))
		*w -= 1;
	if (*temp && *temp != *w)
	{
		ft_printf("Error\nmap size error\n");
		while (line)
		{
			free(line);
			line = get_next_line(fd);
		}
		close(fd);
		exit(1);
	}
	*temp = *w;
}

void	ft_check_map_size(t_game *game)
{
	int	screen_width;
	int	screen_height;
	int	map_width;
	int	map_height;

	mlx_get_screen_size(game->mlx, &screen_width, &screen_height);
	map_width = game->width * 32;
	map_height = game->height * 32;
	if (map_width > screen_width || map_height > screen_height)
	{
		ft_printf("Invalid Map: Map size exceeds screen resolution.");
		close_game(game);
	}
}

void	map_helper(t_game *game, char *map_file, int h, int w)
{
	int	fd;
	int	i;

	i = 0;
	game->width = w;
	game->height = h;
	game->map = (char **)malloc(sizeof(char *) * h);
	if (!game->map)
	{
		ft_printf("Error\n no memory for map\n");
		exit(1);
	}
	fd = open(map_file, O_RDONLY);
	while (i < h)
	{
		game->map[i] = get_next_line(fd);
		game->map[i][w] = '\0';
		i++;
	}
	close (fd);
}

void	map(t_game *game, char *map_file)
{
	int		fd;
	char	*line;
	int		h;
	int		w;
	int		temp;

	temp = 0;
	h = 0;
	w = 0;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nerror opening file\n");
		exit(1);
	}
	line = get_next_line(fd);
	while (line)
	{
		check_width(line, &w, &temp, fd);
		h++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	map_helper(game, map_file, h, w);
}
