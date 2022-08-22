/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nansonm <ansonmng@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:15:46 by nansonm           #+#    #+#             */
/*   Updated: 2022/07/14 12:58:56 by nansonm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
Reads in the map data check its validity, get height and length of the map
*/
static int ft_read_map_file(char *fn, int *height, int *length, t_map **map)
{
	int	fd;
	int	last_state;
	size_t nsize;

	*height = 0;
	*length = 0;
	fd = open(fn, 0_RDONLY);
	if (fd < 0)
		return (0);
	(*map)->map_data = malloc(sizeof(char **) * 1);
	if (!((*map)->map_data))
		return(0);
	last_state = get_next_line(fd, &(*map)->map_data[*height]);
	while (last_state == 1)
	{
		*length = ft_strlen((*map)->map_data[*height]);
		(*height)++;
		nsize = sizeof(char **) * (*height + 1);
		(*map)->map_data = ft_realloc((void **)&(*map)->map_data, nsize);
		last_state = get_next_line(fd, &(*map)->map_data[*height]);
	}
	close(fd);
	return (1);
}

/*
Free map data
*/
void ft_free_map_data(char ***map_data, int size)
{
	int count;

	count = 0;
	while (count <= size)
	{
		free((*map_data)[count]);
		count++;
	}
	free((*map_data));
	(*map_data) = NULL;
}

/*
Return the map struct with data, and check all arguments are fulfilled 
*/
int	ft_get_map(int argc, char *argv[], t_map **map)
{
	char **map_data;
	int		map_h;
	int		map_l;

	map_data = NULL;
	(*map) = malloc(sizeof(t_map));
	if (argc != 1 && (*map) && ft_check_filename(argv[1]))
	{
		if (!ft_read_map_file(argv[1], &map_h, &map_l, map))
		{
			free((*map));
			(*map) = NULL;
			return (0);
		}
		(*map)->map_height = map_h;
		(*map)->map_length = map_l;
		(*map)->max_score = ft_max_score((*map));
		if (ft_check_map_data(map))
			return(1);
		ft_free_map_data(&((*map)->map_data), map_h);
	}
	(*map)->map_data = NULL;
	free((*map));
	(*map) = NULL;
	return (0);
}