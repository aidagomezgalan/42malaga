/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectable_actions_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:53:48 by aidgomez          #+#    #+#             */
/*   Updated: 2024/02/27 13:03:34 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	are_collected(t_items *imap)
{
	int	collected;

	collected = items_count(imap->map, 'C');
	if (collected == 0)
		return (1);
	return (0);
}

void	eating(t_items *imap)
{
	int	i;

	i = 0;
	while (i < imap->collect->count)
	{
		if (imap->collect->instances[i].x == imap->player->instances[0].x
			&& imap->collect->instances[i].y == imap->player->instances[0].y)
		{
			printf("Ñam, ñam! Sugar in vein!!\n");
			imap->eated->instances[i].enabled = true;
			imap->collect->instances[i].enabled = false;
		}
		i++;
	}
}
