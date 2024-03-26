/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:41:21 by aidgomez          #+#    #+#             */
/*   Updated: 2024/02/29 20:44:00 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	flood_fill(char **tab, t_point size, t_point begin)
{
	tab[begin.y][begin.x] = '1';
	if (begin.y > 0 && begin.y < (size.y - 1))
	{
		if (tab[begin.y - 1][begin.x] != '1')
			flood_fill(tab, size, (t_point){begin.x, begin.y - 1});
		if (tab[begin.y + 1][begin.x] != '1')
			flood_fill(tab, size, (t_point){begin.x, begin.y + 1});
	}
	if (begin.x > 0 && begin.x < (size.x - 1))
	{
		if (tab[begin.y][begin.x - 1] != '1')
			flood_fill(tab, size, (t_point){begin.x - 1, begin.y});
		if (tab[begin.y][begin.x + 1] != '1')
			flood_fill(tab, size, (t_point){begin.x + 1, begin.y});
	}
}

char	**make_area(char **zone, t_point size)
{
	int		i;
	char	**new;

	i = 0;
	new = ft_calloc((size.y + 1), sizeof(char *));
	if (!new)
		return (NULL);
	while (zone[i])
	{
		new[i] = ft_strdup(zone[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}
