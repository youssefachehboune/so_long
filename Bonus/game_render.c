/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachehbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:23:08 by yachehbo          #+#    #+#             */
/*   Updated: 2022/02/24 18:23:10 by yachehbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	put_img(t_data *map, int i, int j, void *img_ptr)
{
	mlx_put_image_to_window(map->mlx, map->win, \
	img_ptr, j * 40, i * 40);
}

void	display_move(t_data *var)
{
	char	*move;

	move = add_move(var->player_moves);
	mlx_put_image_to_window(var->mlx, var->win, var->black_img, 0, 0);
	mlx_string_put(var->mlx, var->win, 0, \
		0, 0xB33030, move);
	free(move);
}

void	set_img_bonus(t_data *var, int i, int j)
{
	put_img(var, i, j, var->floor_img);
	if (var->map[i][j] == 'P')
		put_img(var, i, j, var->player_img);
	else if (var->map[i][j] == 'C')
		put_img(var, i, j, var->coin_img);
	else if (var->map[i][j] == 'E')
		put_img(var, i, j, var->door_img);
	else if (var->map[i][j] == 'D')
	{
		put_img(var, i, j, var->enemy_img);
		var->enemy_i = i;
		var->enemy_j = j;
	}
}

void	map_render(t_data *var, int i, int j)
{
	while (var->map[++i])
	{
		j = -1;
		while (var->map[i][++j])
		{
			if (var->map[i][j] == '1')
				put_img(var, i, j, var->wall_img);
			else
			{
				set_img_bonus(var, i, j);
			}
		}
	}
	display_move(var);
}
