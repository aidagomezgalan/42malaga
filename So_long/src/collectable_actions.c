/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectable_actions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:43:20 by aidgomez          #+#    #+#             */
/*   Updated: 2024/02/29 19:41:37 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	instances_img_visibility(mlx_image_t *img, int state)
{
	int	i;

	i = 0;
	while (i < img->count)
	{
		img->instances[i].enabled = state;
		i++;
	}
}

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
			ft_printf("Ñam, ñam! Sugar in vein!!\n");
			imap->eated->instances[i].enabled = true;
			imap->collect->instances[i].enabled = false;
		}
		i++;
	}
}
