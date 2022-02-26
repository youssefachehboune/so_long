/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachehbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 20:00:32 by yachehbo          #+#    #+#             */
/*   Updated: 2022/02/20 20:02:03 by yachehbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	win(void)
{
	ft_printf("You Win\n");
	exit(0);
}

void	player_d(t_data *var)
{
	if (var->map[var->player_i][var->player_j + 1] != '1')
	{
		if ((var->map[var->player_i][var->player_j + 1] == 'E')
			&& (var->collect != 0))
			return ;
		else if ((var->map[var->player_i][var->player_j + 1] == 'E')
			&& (var->collect == 0))
			win();
		if ((var->map[var->player_i][var->player_j + 1] == 'C')
			&& (var->collect != 0))
		{
			var->collect--;
			var->map[var->player_i][var->player_j + 1] = '0';
		}
		var->player_j += 1;
		var->player_moves++;
		ft_printf("player moves: %d\n", var->player_moves);
		put_image(var, var->floor_img, var->player_j - 1, var->player_i);
		put_image(var, var->player_d_img, var->player_j, var->player_i);
	}
}

void	player_a(t_data *var)
{
	if (var->map[var->player_i][var->player_j - 1] != '1')
	{
		if ((var->map[var->player_i][var->player_j - 1] == 'E')
			&& (var->collect != 0))
			return ;
		else if ((var->map[var->player_i][var->player_j - 1] == 'E')
			&& (var->collect == 0))
			win();
		if ((var->map[var->player_i][var->player_j - 1] == 'C')
			&& (var->collect != 0))
		{
			var->map[var->player_i][var->player_j - 1] = '0';
			var->collect--;
		}
		var->player_j -= 1;
		var->player_moves++;
		ft_printf("player moves: %d\n", var->player_moves);
		put_image(var, var->floor_img, var->player_j + 1, var->player_i);
		put_image(var, var->player_a_img, var->player_j, var->player_i);
	}
}

void	player_s(t_data *var)
{
	if (var->map[var->player_i + 1][var->player_j] != '1')
	{
		if ((var->map[var->player_i + 1][var->player_j] == 'E')
			&& (var->collect != 0))
			return ;
		else if ((var->map[var->player_i + 1][var->player_j] == 'E')
			&& (var->collect == 0))
			win();
		if ((var->map[var->player_i + 1][var->player_j] == 'C')
			&& (var->collect != 0))
		{
			var->map[var->player_i + 1][var->player_j] = '0';
			var->collect--;
		}
		var->player_i += 1;
		var->player_moves++;
		ft_printf("player moves: %d\n", var->player_moves);
		put_image(var, var->floor_img, var->player_j, var->player_i - 1);
		put_image(var, var->player_s_img, var->player_j, var->player_i);
	}
}

void	player_w(t_data *var)
{
	if (var->map[var->player_i - 1][var->player_j] != '1')
	{
		if ((var->map[var->player_i - 1][var->player_j] == 'E')
			&& (var->collect != 0))
			return ;
		else if ((var->map[var->player_i - 1][var->player_j] == 'E')
			&& (var->collect == 0))
			win();
		if ((var->map[var->player_i - 1][var->player_j] == 'C')
			&& (var->collect != 0))
		{
			var->map[var->player_i - 1][var->player_j] = '0';
			var->collect--;
		}
		var->player_i -= 1;
		var->player_moves++;
		ft_printf("player moves: %d\n", var->player_moves);
		put_image(var, var->floor_img, var->player_j, var->player_i + 1);
		put_image(var, var->player_w_img, var->player_j, var->player_i);
	}
}
