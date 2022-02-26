/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachehbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:27:00 by yachehbo          #+#    #+#             */
/*   Updated: 2022/02/20 17:48:34 by yachehbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	rectangle(char **map)
{
	int	i;

	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[0]) != ft_strlen(map[i]))
			return (0);
		i++;
	}
	return (1);
}

int	wall(char **map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (map[i])
		i++;
	j = 0;
	len = ft_strlen(map[0]);
	while (map[i - 1][j] && map[0][j])
	{
		if (map[0][j] != '1' || map[i - 1][j] != '1')
			return (0);
		j++;
	}
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (0);
		i++;
	}
	if ((i - 1) == len)
		return (0);
	return (1);
}

int	pec_check(t_data *var)
{
	int	i;
	int	j;

	i = -1;
	while (var->map[++i])
	{
		j = -1;
		while (var->map[i][++j])
		{
			if ((var->map[i][j] != '0') && (var->map[i][j] != '1')
					&& (var->map[i][j] != 'P') && (var->map[i][j] != 'C')
					&& (var->map[i][j] != 'E'))
				return (0);
			if (var->map[i][j] == 'C')
				var->collect++;
			if (var->map[i][j] == 'P')
				var->player++;
			if (var->map[i][j] == 'E')
				var->exit++;
		}
	}
	if (!var->collect || !var->exit || var->player != 1)
		return (0);
	return (1);
}

int	check_map(t_data *var)
{
	var->collect = 0;
	var->exit = 0;
	var->player = 0;
	var->player_moves = 0;
	if (!rectangle(var->map) || !wall(var->map) || !pec_check(var))
	{
		ft_printf("Error\n");
		if (!rectangle(var->map))
			ft_printf("  -Check if the map is rectangle\n");
		if (!wall(var->map))
			ft_printf("  -Check the wall of map\n");
		if (!pec_check(var))
			ft_printf("  -The map don't composed of some character\n");
		return (0);
	}
	return (1);
}
