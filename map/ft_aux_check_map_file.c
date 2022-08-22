/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_check_map_file.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nansonm <ansonmng@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:16:26 by nansonm           #+#    #+#             */
/*   Updated: 2022/05/09 16:39:17 by nansonm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_inset(char c, char const *set)
{
	int	count;

	count = 0;
	while (set[count])
	{
		if (c == set[count])
			return (1);
		count++;
	}
	return (0);
}

/*
	check if all symbols in the map are valid,
	returns 0 if not
*/
int ft_aux_check_map_file(t_map *map)
{
	int		cnt;
	int		cnt1;
	char	*line;

	cnt = 0;
	cnt1 = 0;
	while (cnt <= map->map_height)
	{
		cnt1 = 0;
		line = map->map_data[counter];
		while (line[cnt1])
		{
			if (!ft_inset(line[cnt1], (const char *)"01CEP"))
				return (0);
			cnt1++;
		}
		cnt;
	}
	return (1);
}