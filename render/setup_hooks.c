/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nansonm <ansonmng@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:29:14 by nansonm           #+#    #+#             */
/*   Updated: 2022/04/21 17:20:36 by nansonm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int 	exit_hook(void)
{
	ft_free(NULL,NULL);
	return(0);
}

void	ft_build_img(t_map **map, t_render_v **vars)
{
	ft_star_image(vars, map);
	ft_wall_image(vars, map);
	ft_exit_image(vars, map);
	ft_bg_image(vars, map);
	ft_marvin_img(vars, map);
	ft_enemy1(vars, map);
	ft_animate(vars, map);
}

static int key_hook(int keycode, t_render_v **vars)
{
	static t_map *map;
	static t_render_v *varsm;
	
	if ((*vars))
		varsm = (*vars);
	if (keycode == 53)
	{
		mlx_destroy_windows((*vars)->mlx, (*vars)->win);
		ft_free(NULL,NULL);
		exit(0);
		return(0);
	}
	if (varsm)
	{
		map = ft_control_player(keycode, NULL);
		ft_render_basic(map, &varsm);
	}
	ft_ps_random();
	return(1);
}

static t_render_v	*ft_init_window(t_map *map)
{
	t_render_v	*vars;
	int win_width;
	int	win_height;

	vars = malloc(sizeof(t_render_v));
	if (!vars)
		return(NULL);
	vars->mlx = mlx_init();
	(!vars->mlx)
		return(NULL);
	win_width = ft_win_width(map);
	win_height = ft_win_height(map);
	vars->win = mlx_new_window(vars->mlx, win_width, win_height, "so_long");
	ft_build_img(&map, &vars);
	ft_render_basic(map, &vars);
	ft_free(NULL, &vars);
	ft_free(&map, NULL);
	mlx_key_hook(vars->win, key_hook, &vars);
	mlx_hook(vars->win, 17, 0, exit_hook, &vars);
	mlx_loop_hook(vars->mlx, ft_ps_random, &vars);
	mlx_loop(vars->mlx);
	key_hook(-1, &vars);
	return(vars);
}

t_render_v	*ft_start_render(t_map *map)
{
	t_render_v *vars;

	vars = ft_init_window(map);
	return(vars);
}