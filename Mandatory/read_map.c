/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachehbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:20:44 by yachehbo          #+#    #+#             */
/*   Updated: 2022/02/20 17:33:01 by yachehbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

char	**read_map(char *str)
{
	int		fd;
	char	*line;
	char	*hold_map;
	char	**map;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nDon't find the map file");
		exit (0);
	}
	hold_map = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == '\n')
			break ;
		hold_map = ft_strjoin(hold_map, line);
		free(line);
		line = get_next_line(fd);
	}
	map = ft_split(hold_map, '\n');
	free(hold_map);
	return (map);
}
