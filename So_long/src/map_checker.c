/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:32:04 by aidgomez          #+#    #+#             */
/*   Updated: 2024/02/29 19:16:39 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_name(char *str)
{
	int	last;

	last = ft_strlen(str) - 1;
	if (!str || last < 4)
		return (0);
	if (str[last] == 'r' && str[last - 1] == 'e' && str[last - 2] == 'b'
		&& str[last - 3] == '.')
		return (1);
	return (0);
}

int	is_rectangle(char **map)
{
	int		i;
	size_t	row_len;
	int		rows;

	i = 1;
	rows = array_len(map);
	if (!map[0])
		return (0);
	row_len = ft_strlen(map[0]);
	while (i < rows)
	{
		if (row_len != ft_strlen(map[i]))
			return (0);
		i++;
	}
	return (1);
}

int	are_items(char **map)
{
	int	exit;
	int	player;
	int	collect;

	exit = items_count(map, 'E');
	player = items_count(map, 'P');
	collect = items_count(map, 'C');
	if (exit > 1 || exit == 0 || player > 1 || player == 0 || collect == 0)
		return (0);
	return (1);
}

int	is_valid_path(char **map)
{
	t_point	size;
	t_point	begin;
	char	**area;
	int		i;
	int		j;

	i = -1;
	size = map_size(map);
	begin = item_axes(map, 'P');
	area = make_area(map, size);
	flood_fill(area, size, begin);
	while (++i < size.y)
	{
		j = -1;
		while (area[i][++j])
		{
			if (area[i][j] == 'E' || area[i][j] == 'C')
			{
				memory_str_free(area);
				return (0);
			}
		}
	}
	memory_str_free(area);
	return (1);
}

int	is_valid_map(char *str)
{
	int		last_row;
	char	**map;

	map = fd_to_array(str);
	if (!map)
		return (0);
	if (!is_valid_name(str) || !is_rectangle(map))
		return (memory_str_free(map), 0);
	last_row = array_len(map) - 1;
	if (!is_wall(map[0]) || !is_wall(map[last_row]))
		return (memory_str_free(map), 0);
	if (!is_path(map))
		return (memory_str_free(map), 0);
	if (!are_items(map) || !is_valid_path(map))
		return (memory_str_free(map), 0);
	memory_str_free(map);
	return (1);
}
