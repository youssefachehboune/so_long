/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachehbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:45:13 by yachehbo          #+#    #+#             */
/*   Updated: 2022/02/25 14:45:37 by yachehbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	key_hook(int code, t_data *var)
{
	if (code == KEY_A)
		player_a_bonus(var);
	else if (code == KEY_D)
		player_d_bonus(var);
	else if (code == KEY_W)
		player_w_bonus(var);
	else if (code == KEY_S)
		player_s_bonus(var);
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
