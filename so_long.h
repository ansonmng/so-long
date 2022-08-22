/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nansonm <ansonmng@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:23:37 by nansonm           #+#    #+#             */
/*   Updated: 2022/04/18 18:14:43 by nansonm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <mlx.h>
#include "libft.h"

typedef struct s_map {
	int	map_height;
	int	map_length;
	int	player_position_x;
	int	player_position_y;
	int	max_score;
	int game_score;
	char **map_data;
	int	game_over;
	int	steps;
	void	*wall;
	void	*exit;
	void	*player;
	void	*bg;
	void	*star;
	void	*enemy;
	void	*marvin;
	int	drawP;
	int	*enemyPos;
	int	enemySet;
	char *err_msg;
}	t_map;

typedef struct s_render_v {
	void *mlx;
	void *win;
} t_render_v; 