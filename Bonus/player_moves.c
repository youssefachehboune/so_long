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

void	player_d_bonus(t_data *var)
{
	if (var->map[var->player_i][var->player_j + 1] != '1')
	{
		if ((var->map[var->player_i][var->player_j + 1] == 'E')
			&& (var->collect != 0))
			return ;
		else if ((var->map[var->player_i][var->player_j + 1] == 'E')
			&& (var->collect == 0))
			win();
		else if (var->map[var->player_i][var->player_j + 1] == 'D')
			exit(0);
		if ((var->map[var->player_i][var->player_j + 1] == 'C')
			&& (var->collect != 0))
		{
			var->collect--;
		}
		var->player_j += 1;
		var->player_moves++;
		var->map[var->player_i][var->player_j] = 'P';
		var->map[var->player_i][var->player_j - 1] = '0';
		var->derection = 'D';
	}
}

void	player_a_bonus(t_data *var)
{
	if (var->map[var->player_i][var->player_j - 1] != '1')
	{
		if ((var->map[var->player_i][var->player_j - 1] == 'E')
			&& (var->collect != 0))
			return ;
		else if ((var->map[var->player_i][var->player_j - 1] == 'E')
			&& (var->collect == 0))
			win();
		else if (var->map[var->player_i][var->player_j - 1] == 'D')
			exit(0);
		if ((var->map[var->player_i][var->player_j - 1] == 'C')
			&& (var->collect != 0))
		{
			var->collect--;
		}
		var->player_j -= 1;
		var->player_moves++;
		var->map[var->player_i][var->player_j] = 'P';
		var->map[var->player_i][var->player_j + 1] = '0';
		var->derection = 'A';
	}
}

void	player_s_bonus(t_data *var)
{
	if (var->map[var->player_i + 1][var->player_j] != '1')
	{
		if ((var->map[var->player_i + 1][var->player_j] == 'E')
			&& (var->collect != 0))
			return ;
		else if ((var->map[var->player_i + 1][var->player_j] == 'E')
			&& (var->collect == 0))
			win();
		else if (var->map[var->player_i + 1][var->player_j] == 'D')
			exit(0);
		if ((var->map[var->player_i + 1][var->player_j] == 'C')
			&& (var->collect != 0))
		{
			var->collect--;
		}
		var->player_i += 1;
		var->player_moves++;
		var->map[var->player_i][var->player_j] = 'P';
		var->map[var->player_i - 1][var->player_j] = '0';
		var->derection = 'S';
	}
}

void	player_w_bonus(t_data *var)
{
	if (var->map[var->player_i - 1][var->player_j] != '1')
	{
		if ((var->map[var->player_i - 1][var->player_j] == 'E')
			&& (var->collect != 0))
			return ;
		else if ((var->map[var->player_i - 1][var->player_j] == 'E')
			&& (var->collect == 0))
			win();
		else if (var->map[var->player_i - 1][var->player_j] == 'D')
			exit(0);
		if ((var->map[var->player_i - 1][var->player_j] == 'C')
			&& (var->collect != 0))
		{
			var->collect--;
		}
		var->player_i -= 1;
		var->player_moves++;
		var->map[var->player_i][var->player_j] = 'P';
		var->map[var->player_i + 1][var->player_j] = '0';
		var->derection = 'W';
	}
}
