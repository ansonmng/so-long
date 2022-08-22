/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nansonm <ansonmng@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 15:04:07 by nansonm           #+#    #+#             */
/*   Updated: 2022/07/14 15:35:51 by nansonm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static t_map *ft_check_collectible(t_map *map)
{
	int x;
	int y;

	y = map->player_position_y / TILE_WIDTH;
	x = map->player_position_x / TILE_WIDTH;
	if (map->map_data[y][x] == 'C')
	{
		map->map_data[y][x] = '0';
		map->game_score++;
		ft_ps_random();
	}
	return(map);
}

t_map *ft_control_player(int keycode, t_map *inj_map)
{
	static t_map	*map;
	static int	end_game= 0;

	ft_ps_random();
	if (map && (end_game == 0))
	{
		map = ft_keycode_action(map, keycode);
		map = ft_check_collectible(map);
	}
	else if (inj_map && (end_game == 0))
	{
		map = inj_map;
		if (inj_map->game_over)
			end_game = 1;
		else
			ft_find_player(map, &map->player_position_x, &map->player_position_y);
	}
	return(map);
}