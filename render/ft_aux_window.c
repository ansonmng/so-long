/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nansonm <ansonmng@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:58:34 by nansonm           #+#    #+#             */
/*   Updated: 2022/04/25 18:01:39 by nansonm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int ft_window_height(t_map *map)
{
	return (((map->map_height) + 1) * TILE_WIDTH);
}

int ft_window_width(t_map *map)
{
	return ((map->map_length) * TILE_WIDTH);
}

int ft_whc(t_map *map)
{
	return (((map->map_height) + 1) * TILE_WIDTH) / 2);
}

int ft_wwc(t_map *map)
{
	return (((map->map_length) * TILE_WIDTH) / 2);
}