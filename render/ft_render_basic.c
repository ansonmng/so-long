/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_basic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nansonm <ansonmng@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:49:42 by nansonm           #+#    #+#             */
/*   Updated: 2022/04/20 19:55:35 by nansonm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void ft_render_enemy(t_render_v **vars, t_map map)
{
		int pos[2];
		static int	rand;

		if (BONUS == 1)
		{
			rand = ft_ps_random() % 3;
			ft_enemy1(vars, map);
			if (rand == 1)
				ft_enemy2(vars, map);
			pos[0] = ((*map)->enemyPos[0] * TILE_WIDTH);
			pos[1] = ((*map)->enemyPos[1] * TILE_WIDTH);
			ft_put_img(vars, (*map)->enemy, pos[0], pos[1]);
		}
}

static void ft_put_player(t_render_v **vars, t_map *map)
{
	int pos[2];

	pos[0] = map->player_position_x;
	pos[1] = map->player_position_y;
	ft_put_img(vars, map->marvin, pos[0], pos[1]);
}

static void ft_tile(char t, t_render_v **v, int *pos, t_map **map)
{
	(*map)->drawP++;
	ft_put_img(v, (*map)->bg, pos[0], pos[1]);
	if (t == '1')
	{
		ft_tree1(v, map);
		if((*map)->drawP % 2)
			ft_tree2(v, map);
		if((*map)->drawP % 3)
			ft_tree3(v, map);
		ft_put_img(v, (*map)->wall, pos[0], pos[2]);
	}
	if (t == 'C')
		ft_put_img(v, (*map)->star, pos[0], pos[2]);
	if (t == 'E')
		ft_put_img(v, (*map)->exit, pos[0], pos[2]);
}

static void	ft_draw_content(t_render_v **vars, t_map *map)
{
	int y_pos;
	int x_pos;
	char current;
	int pos[2];

	ft_set_startv_render(&count, &char_counter);
	pos[0] = 0;
	pos[1] = 0;
	map->drawP = 0;
	while (y_pos <= map->map_height && vars)
	{
		char_cnt = 0;
		pos[0] = 0;
		while (map->map_data[y_pos][x_pos] != 0 )
		{
			current = map->map_data[y_pos][x_pos];
			ft_tile(current, vars, pos, &map);
			x_pos++;
			pos[0] += TILE_WIDTH;
		}
		pos[1] += TILE_WIDTH;
		y_pos++;
	}
	ft_render_enemy(vars, &map);
	ft_put_player(vars, map);
}

void	ft_render_basic(t_map *map, t_render_v **vars)
{
	void *p[2];
	char *go;

	p[0] = (*vars)->mlx;
	p[1] = (*vars)->win;
	go = "You Won!";
	if (map->map_data && vars && !(map->game_over))
	{
		mlx_clear_window((*vars)->mlx, (*vars)->win);
		if((!ft_game_over(map, vars) && p[1] && p[0])
		{
			ft_animate(&map, vars);
			ft_ps_random();
			ft_if_putenemy(map);
			ft_draw_content(vars, map);
			ft_put_steps(vars, map);
			if (BONUS)
				ft_move_enemy(map);
		}
	}
}