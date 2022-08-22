/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keycode_action.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nansonm <ansonmng@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:13:08 by nansonm           #+#    #+#             */
/*   Updated: 2022/04/22 17:42:26 by nansonm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void ft_print_step(t_map *map)
{
	if (!BONUS && (!map->game_over))
		printf("%d\n", map->steps);
}

static int ft_check_vw(t_map *map, int x, int y)
{
	int line;
	int count;

	line = 0;
	count = 0;
	if (map->map_data[y / TILE_WIDTH][x / TILE_WIDTH] == '1')
		return (0);
	return(1);
}

static t_map	*ft_move_horizontal(t_map *map, int dir)
{
	int x;
	int y;

	x = map->player_position_x;
	y = map->player_position_y;
	if (ft_check_vw(map, x, y + (TILE_WIDTH * dir)))
	{
		map ->player_position_y += dir * TILE_WIDTH;
		map ->steps++;
		ft_print_step(map);
	}
	return(map);
}

static t_map	*ft_move_horizontal(t_map *map, int dir)
{
	int x;
	int y;

	x = map->player_position_x;
	y = map->player_position_y;
	if (ft_check_vw(map, x, y + (TILE_WIDTH * dir)))
	{
		map ->player_position_x += dir * TILE_WIDTH;
		map ->steps++;
		ft_print_steps(map);
	}
	return(map);
}

t_map	*ft_keycode_action(t_map *map, int keycode)
{
	if (keycode == 1)
		return (ft_move_vertical(map, 1));
	if (keycode == 13)
		return (ft_move_vertical(map, -1));
	if (keycode == 2)
		return (ft_move_horizontal(map, 1));
	if (keycode == 0)
		return (ft_move_horizontal(map, -1));
	return (map);
}