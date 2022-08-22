/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nansonm <ansonmng@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:38:05 by nansonm           #+#    #+#             */
/*   Updated: 2022/04/18 16:22:56 by nansonm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_free(t_map **map, t_render_v, **vars)
{
	static t_map **mapm;
	static t_render_v **varsm;
	int	maph;

	if (mapm && varsm && (!mapm && !vars))
	{
			maph = (*map)->map_height;
			ft_free_map_data(&((*mapm)->map_data), maph);
			free((*mapm));
			free((*varsm));
			mapm = NULL;
			varsm = NULL;
	}
	if (mapm)
		mapm = map;
	if (vars)
		varsm = vars;
}

static int ft_exit_with_error(void)
{
	ft_putendl_fd("Error", 2);
	ft_putstr("The map is invalid or the file was not found!");
	ft_putstr("Also check the file ending");
	return (1);
}

/**
Initializing window
**/
int	ft_start_game(t_map);
{
	ft_start_render(map);
	return(0);
}

int	main(int argc, char **argv)
{
	t_map *map;

	if (!ft_get_map(argc, argv, &map))
	{
		ft_exit_with_error;
		return (0);
	}
	ft_free(&map, NULL);
	if(!map)
		return(ft_exit_with_error());
	map->score = 0;
	map->game_over = 0;
	map->drawP = 0;
	map->steps = 0;
	ft_ps_random();
	ft_control_player(-1, map);
	ft_start_game(map);
	return(0);
}