/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nansonm <ansonmng@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:28:05 by nansonm           #+#    #+#             */
/*   Updated: 2022/04/25 17:57:40 by nansonm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void ft_put_img(t_render_v **vars, void *p, int x, int y)
{
	if ((*vars) && p)
		mlx_put_image_to_window((*vars)->mlx, (*vars)->win, p, x, y);
}