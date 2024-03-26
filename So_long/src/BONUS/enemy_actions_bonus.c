/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_actions_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:58:05 by aidgomez          #+#    #+#             */
/*   Updated: 2024/02/26 17:03:44 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	game_over(void *param)
{
	int		i;
	t_items	*imap;

	imap = (t_items *)param;
	i = 0;
	while (i < imap->enemy->count)
	{
		if (imap->enemy->instances[i].x == imap->player->instances[0].x
			&& imap->enemy->instances[i].y == imap->player->instances[0].y)
		{
			imap->died->instances[i].enabled = true;
			imap->enemy->instances[i].enabled = false;
			imap->player->instances[0].enabled = false;
			imap->smile->instances[0].enabled = false;
			imap->bigsmile->instances[0].enabled = false;
			print_end_game("YOU DIED FROM ALLERGY !");
			imap->lock_key = 1;
		}
		i++;
	}
}
