/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachehbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:20:46 by yachehbo          #+#    #+#             */
/*   Updated: 2022/02/24 18:20:49 by yachehbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	file_to_img(t_data *var, char *file)
{
	var->player_img = mlx_xpm_file_to_image(var->mlx, \
		file, &var->img_w, &var->img_h);
}

void	player_right_update(t_data *var)
{
	if (var->count >= 0)
		file_to_img(var, "Bonus/assets/player_d_1.xpm");
	if (var->count >= 5)
		file_to_img(var, "Bonus/assets/player_d_2.xpm");
	if (var->count >= 10)
		file_to_img(var, "Bonus/assets/player_d_3.xpm");
}

void	player_left_update(t_data *var)
{
	if (var->count >= 0)
		file_to_img(var, "Bonus/assets/player_a_1.xpm");
	if (var->count >= 5)
		file_to_img(var, "Bonus/assets/player_a_2.xpm");
	if (var->count >= 10)
		file_to_img(var, "Bonus/assets/player_a_3.xpm");
}

void	player_top_update(t_data *var)
{
	if (var->count >= 0)
		file_to_img(var, "Bonus/assets/player_w_1.xpm");
	if (var->count >= 5)
		file_to_img(var, "Bonus/assets/player_w_2.xpm");
	if (var->count >= 10)
		file_to_img(var, "Bonus/assets/player_w_3.xpm");
}

void	player_bottom_update(t_data *var)
{
	if (var->count >= 0)
		file_to_img(var, "Bonus/assets/player_s_1.xpm");
	if (var->count >= 5)
		file_to_img(var, "Bonus/assets/player_s_2.xpm");
	if (var->count >= 10)
		file_to_img(var, "Bonus/assets/player_s_3.xpm");
}
