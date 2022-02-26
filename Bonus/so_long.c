/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachehbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:18:24 by yachehbo          #+#    #+#             */
/*   Updated: 2022/02/20 17:30:13 by yachehbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	check_ext(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if ((str[i - 4] == '.') && (str[i - 3] == 'b') && (str[i - 2] == 'e')
		&& (str[i - 1] == 'r'))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	var;

	if (ac != 2 || !check_ext(av[1]))
	{
		ft_printf("Error\nWrong Usage");
		return (0);
	}
	var.map = read_map(av[1]);
	if (!var.map[0])
	{
		ft_printf("Error\nWrong Map");
		return (0);
	}
	if (!check_map_bonus(&var))
		return (0);
	init_bonus(&var);
}
