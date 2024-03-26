/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:52:10 by aidgomez          #+#    #+#             */
/*   Updated: 2024/02/29 17:50:02 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_wall(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	is_path(char **str)
{
	size_t	i;
	size_t	j;
	size_t	last_row;
	size_t	last_col;

	i = 1;
	last_row = array_len(str) - 1;
	last_col = ft_strlen(str[0]);
	while (str[i] && i < last_row)
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][0] != '1' && str[i][last_col] != '1')
				return (0);
			if (str[i][j] != 'E' && str[i][j] != '0' && str[i][j] != '1'
				&& str[i][j] != 'C' && str[i][j] != 'P')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

t_point	map_size(char **map)
{
	t_point	size;

	size.x = ft_strlen(map[0]);
	size.y = array_len(map);
	return (size);
}

int	items_count(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

t_point	item_axes(char **map, char c)
{
	int		i;
	int		j;
	t_point	pos;

	i = 0;
	pos.x = -1;
	pos.y = -1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
			{
				pos.x = j;
				pos.y = i;
				return (pos);
			}
			j++;
		}
		i++;
	}
	return (pos);
}
