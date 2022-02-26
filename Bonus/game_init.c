/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachehbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:30:35 by yachehbo          #+#    #+#             */
/*   Updated: 2022/02/20 19:57:52 by yachehbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	init_img_bonus(t_data *var)
{
	var->player_img = mlx_xpm_file_to_image(var->mlx,
			"Bonus/assets/player_d_1.xpm", &var->img_w, &var->img_h);
	var->floor_img = mlx_xpm_file_to_image(var->mlx, "Bonus/assets/floor.xpm",
			&var->img_w, &var->img_h);
	var->coin_img = mlx_xpm_file_to_image(var->mlx, "Bonus/assets/coin.xpm",
			&var->img_w, &var->img_h);
	var->wall_img = mlx_xpm_file_to_image(var->mlx, "Bonus/assets/wall.xpm",
			&var->img_w, &var->img_h);
	var->door_img = mlx_xpm_file_to_image(var->mlx, "Bonus/assets/door.xpm",
			&var->img_w, &var->img_h);
	var->enemy_img = mlx_xpm_file_to_image(var->mlx, "Bonus/assets/enemy_1.xpm",
			&var->img_w, &var->img_h);
	var->black_img = mlx_xpm_file_to_image(var->mlx, "Bonus/assets/black.xpm",
			&var->img_w, &var->img_h);
}

void	set_res(t_data *var)
{
	int	i;

	i = 0;
	while (var->map[i])
		i++;
	var->win_h = i * 40;
	var->win_w = ft_strlen(var->map[0]) * 40;
}

void	init_bonus(t_data *var)
{
	var->mlx = mlx_init();
	set_res(var);
	init_img_bonus(var);
	var->win = mlx_new_window(var->mlx, var->win_w, var->win_h, "so_long");
	map_set_bonus(var, -1, -1);
	game_bonus(var);
	mlx_loop(var->mlx);
}
