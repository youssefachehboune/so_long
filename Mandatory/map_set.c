/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachehbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:39:06 by yachehbo          #+#    #+#             */
/*   Updated: 2022/02/20 16:52:02 by yachehbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	put_image(t_data *var, void *img_ptr, int x, int y)
{
	mlx_put_image_to_window(var->mlx, var->win, img_ptr, x * 40, y * 40);
}

void	map_set(t_data *var)
{
	int	i;
	int	j;

	i = -1;
	while (var->map[++i])
	{
		j = -1;
		while (var->map[i][++j])
		{
			if (var->map[i][j] == '1')
				put_image(var, var->wall_img, j, i);
			else if (var->map[i][j] == '0')
				put_image(var, var->floor_img, j, i);
			else if (var->map[i][j] == 'P')
			{
				put_image(var, var->player_d_img, j, i);
				var->player_i = i;
				var->player_j = j;
			}
			else if (var->map[i][j] == 'E')
				put_image(var, var->door_img, j, i);
			else if (var->map[i][j] == 'C')
				put_image(var, var->coin_img, j, i);
		}
	}
}
