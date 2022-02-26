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

void	init_img(t_data *var)
{
	var->player_w_img = mlx_xpm_file_to_image(var->mlx,
			"Mandatory/assets/player_w.xpm", &var->img_w, &var->img_h);
	var->player_a_img = mlx_xpm_file_to_image(var->mlx,
			"Mandatory/assets/player_a.xpm", &var->img_w, &var->img_h);
	var->player_d_img = mlx_xpm_file_to_image(var->mlx,
			"Mandatory/assets/player_d.xpm", &var->img_w, &var->img_h);
	var->player_s_img = mlx_xpm_file_to_image(var->mlx,
			"Mandatory/assets/player_s.xpm", &var->img_w, &var->img_h);
	var->floor_img = mlx_xpm_file_to_image(var->mlx,
			"Mandatory/assets/floor.xpm", &var->img_w, &var->img_h);
	var->coin_img = mlx_xpm_file_to_image(var->mlx,
			"Mandatory/assets/coin.xpm", &var->img_w, &var->img_h);
	var->wall_img = mlx_xpm_file_to_image(var->mlx,
			"Mandatory/assets/wall.xpm", &var->img_w, &var->img_h);
	var->door_img = mlx_xpm_file_to_image(var->mlx,
			"Mandatory/assets/door.xpm", &var->img_w, &var->img_h);
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

void	init(t_data *var)
{
	var->mlx = mlx_init();
	set_res(var);
	init_img(var);
	var->win = mlx_new_window(var->mlx, var->win_w, var->win_h, "so_long");
	map_set(var);
	game(var);
	mlx_loop(var->mlx);
}
