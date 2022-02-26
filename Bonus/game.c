/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachehbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 19:58:35 by yachehbo          #+#    #+#             */
/*   Updated: 2022/02/20 19:59:43 by yachehbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	check_der(t_data *var)
{
	if (var->der == 1)
		enemy_move_r(var);
	else
		enemy_move_l(var);
}

int	player_update(t_data *var)
{
	var->count++;
	if (var->count <= 15)
	{
		if (var->derection == 'A')
			player_left_update(var);
		else if (var->derection == 'W')
			player_top_update(var);
		else if (var->derection == 'S')
			player_bottom_update(var);
		else if (var->derection == 'D')
			player_right_update(var);
		if (var->der == 1)
			enemy_update(var);
		else if (var->der != 1)
			enemy_update_left(var);
	}
	else
	{		
		check_der(var);
		var->count = 0;
	}
	map_render(var, -1, -1);
	return (0);
}

void	game_bonus(t_data *var)
{
	mlx_loop_hook(var->mlx, &player_update, var);
	mlx_hook(var->win, 02, 0L, key_hook, var);
	mlx_hook(var->win, 17, 0L, key_exit, var);
}
