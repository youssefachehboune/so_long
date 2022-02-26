/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachehbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:49:20 by yachehbo          #+#    #+#             */
/*   Updated: 2022/02/25 15:49:23 by yachehbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	file_to_img_enemy(t_data *var, char *file)
{
	var->enemy_img = mlx_xpm_file_to_image(var->mlx, \
		file, &var->img_w, &var->img_h);
}

void	enemy_update(t_data *var)
{
	if (var->count >= 0)
		file_to_img_enemy(var, "Bonus/assets/enemy_1.xpm");
	if (var->count >= 7)
		file_to_img_enemy(var, "Bonus/assets/enemy_2.xpm");
}

void	enemy_update_left(t_data *var)
{
	if (var->count >= 0)
		file_to_img_enemy(var, "Bonus/assets/enemy_l_1.xpm");
	if (var->count >= 7)
		file_to_img_enemy(var, "Bonus/assets/enemy_l_2.xpm");
}

void	enemy_move_r(t_data *var)
{
	if (var->map[var->enemy_i][var->enemy_j + 1] == '0')
	{
		var->map[var->enemy_i][var->enemy_j] = '0';
		var->map[var->enemy_i][var->enemy_j + 1] = 'D';
	}
	else if (var->map[var->enemy_i][var->enemy_j + 1] == 'P')
	{
		ft_printf("You Lose");
		exit(0);
	}
	else if (var->map[var->enemy_i][var->enemy_j + 1] != '0')
		var->der = -1;
}

void	enemy_move_l(t_data *var)
{
	if (var->map[var->enemy_i][var->enemy_j - 1] == '0')
	{
		var->map[var->enemy_i][var->enemy_j] = '0';
		var->map[var->enemy_i][var->enemy_j - 1] = 'D';
	}
	else if (var->map[var->enemy_i][var->enemy_j - 1] == 'P')
	{
		ft_printf("You Lose");
		exit(0);
	}
	else if (var->map[var->enemy_i][var->enemy_j - 1] != '0')
		var->der = 1;
}
