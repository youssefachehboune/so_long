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

int	key_hook(int code, t_data *var)
{
	if (code == KEY_A)
		player_a(var);
	else if (code == KEY_D)
		player_d(var);
	else if (code == KEY_W)
		player_w(var);
	else if (code == KEY_S)
		player_s(var);
	else if (code == KEY_ESC)
	{
		ft_printf("You exited from the program\n");
		exit(0);
	}		
	return (0);
}

int	key_exit(void)
{
	ft_printf("You exited from the program\n");
	exit(0);
	return (0);
}

void	game(t_data *var)
{
	mlx_hook(var->win, 02, 0L, key_hook, var);
	mlx_hook(var->win, 17, 0L, key_exit, var);
}
