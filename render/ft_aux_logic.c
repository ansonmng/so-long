/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_logic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nansonm <ansonmng@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:03:08 by nansonm           #+#    #+#             */
/*   Updated: 2022/04/25 18:14:37 by nansonm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_game_end(t_map *map)
{
	return (map->max_score == map->game_score);
}

int ft_max_score(t_map *map)
{
	int score;
	int count_y;
	int count_x;

	score = 0;
	count_y = 0;
	count_x = 0;
	while (count_y <= map->map_height)
	{
		count_x = 0;
		while (map->map_data[count_y][count_x])
		{
			if (map->map_data[count_y][count_x] == 'C')
				score++;
			count_x++;
		}
		count_y++;
	}
	return (score);
}
