/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachehbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:39:06 by yachehbo          #+#    #+#             */
/*   Updated: 2022/02/20 16:52:02 by yachehbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

char	*add_move(int k)
{
	char	*str;
	char	*out;
	char	*num;
	int		i;
	int		j;

	i = 0;
	j = 0;
	num = ft_itoa(k);
	str = "Moves :";
	out = (char *)malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(out) + 1));
	while (str[i])
		out[j++] = str[i++];
	i = 0;
	while (num[i])
		out[j++] = num[i++];
	out[j] = '\0';
	free(num);
	return (out);
}

void	put_image(t_data *var, void *img_ptr, int x, int y)
{
	mlx_put_image_to_window(var->mlx, var->win, img_ptr, x * 40, y * 40);
}

void	map_set_bonus(t_data *var, int i, int j)
{
	while (var->map[++i])
	{
		j = -1;
		while (var->map[i][++j])
		{
			if (var->map[i][j] == '1')
				put_image(var, var->wall_img, j, i);
			else if (var->map[i][j] == '0')
				put_image(var, var->floor_img, j, i);
			else if (var->map[i][j] == 'P')
			{
				put_image(var, var->player_img, j, i);
				var->player_i = i;
				var->player_j = j;
			}
			else if (var->map[i][j] == 'E')
				put_image(var, var->door_img, j, i);
			else if (var->map[i][j] == 'C')
				put_image(var, var->coin_img, j, i);
			else if (var->map[i][j] == 'D')
				put_image(var, var->enemy_img, j, i);
		}
	}
}
