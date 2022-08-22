/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nansonm <ansonmng@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:35:06 by nansonm           #+#    #+#             */
/*   Updated: 2022/05/09 17:13:46 by nansonm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
Checks if all the lines have the same length, 
return 1 if true, return 0 is false
*/
static int ft_check_length (t_map *map)
{
	int	line_l;
	int	shoukd_l;
	int	is_l;
	int	cl;

	cl = 0;
	should_l = 0;
	is_l = 0;
	line_l = ft_strlen(map->map_data[0]);
	while (c1 <= map->map_height)
	{
		is_l += ft_strlen(map->map_data[(cl)]);
		should_l += line_l;
		cl ++;
	}
	return (is _l == should_l);
}

/*
Checks if there is at least 1 exit
*/
static int	ft_check_exit(t_map *map)
{
	int		exit_count;
	int		count;
	char	*line;

	count = 0;
	exit_count = 0;
	while (count <= map->map_height)
	{
		line = map->map_data[count];
		if (ft_strchr(line, 'E'))
			exit_count++;
		count ++;
	}
	return (exit_count);
}

/*
	Check if there is only 1 player
*/
static unsigned long	ft_check_player(t_map *map)
{
	int		count;
	char	*pos;
	char	*pos2;
	char	*line;

	pos = 0;
	count = 0;
	pos2 = 0;
	while (count <= map->map_height)
	{
		line = map->map_data[count];
		if (pos)
			pos2 = ft_returnlinechr(line, 'P');
		if (!pos)
			pos = ft_returnlinechr(line, 'P');
		if (pos2)
			return(0);
		count++;
	}
	return (!!pos);
}

/*
Checks if the walls are coherent
*/
static int	ft_checks_walls(t_map	*map)
{
	int		count;
	int		flag;
	char	*temp;

	count = 0;
	flag = 1;
	if (!ft_check_is_wall(map->map_data[0]))
		return(0);
	if (!ft_check_is_wall(map->map_data[map->map_height])
		return(0);
	while (count <= map->map_height)
	{
		temp = map->map_data[count];
		if (temp[0] != '1')
			flag = 0;
		if (temp[ft_strlen(temp) - 1] != '1')
			flag = 0;
		count ++;
	}
	return (flag); 
}

/*
**	This checks the map struct for validity and rules:
**  - All lines have same length
**  - Theres exactly one player symbol
**  - The map is surrounded by walls
**  - There is atleast one exit
**	- There is atleast one collectable
**	- Checks if there is any invalid symbol
*/
int	ft_check_map_data(t_game_map **game_map)
{
	if (!ft_check_length((*game_map)))
		return (0);
	if (!ft_check_walls((*game_map)))
		return (0);
	if (!ft_check_player((*game_map)))
		return (0);
	if (ft_check_exit((*game_map)) == 0)
		return (0);
	if (ft_max_score((*game_map)) == 0)
		return (0);
	if (!ft_aux_check_map_file((*game_map)))
		return (0);
	return (1);
}