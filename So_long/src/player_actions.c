/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:30:08 by aidgomez          #+#    #+#             */
/*   Updated: 2024/02/29 17:43:47 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_update(t_items *imap, char key)
{
	if (key == 'a')
	{
		imap->player->instances[0].x -= PX;
		imap->smile->instances[0].x -= PX;
		imap->bigsmile->instances[0].x -= PX;
	}
	else if (key == 'd')
	{
		imap->player->instances[0].x += PX;
		imap->smile->instances[0].x += PX;
		imap->bigsmile->instances[0].x += PX;
	}
	else if (key == 'w')
	{
		imap->player->instances[0].y -= PX;
		imap->smile->instances[0].y -= PX;
		imap->bigsmile->instances[0].y -= PX;
	}
	else if (key == 's')
	{
		imap->player->instances[0].y += PX;
		imap->smile->instances[0].y += PX;
		imap->bigsmile->instances[0].y += PX;
	}
	moves_count(imap);
}

void	moves_count(t_items *imap)
{
	imap->player_moves++;
	ft_printf("Player moves: %i\n", imap->player_moves);
}

void	img_visibility(t_items *imap)
{
	if (imap->player->instances[0].enabled == true)
	{
		imap->player->instances[0].enabled = false;
		imap->smile->instances[0].enabled = true;
		imap->bigsmile->instances[0].enabled = false;
	}
	else if (imap->smile->instances[0].enabled == true)
	{
		imap->player->instances[0].enabled = false;
		imap->smile->instances[0].enabled = false;
		imap->bigsmile->instances[0].enabled = true;
	}
	else if (imap->bigsmile->instances[0].enabled == true)
	{
		imap->player->instances[0].enabled = true;
		imap->smile->instances[0].enabled = false;
		imap->bigsmile->instances[0].enabled = false;
	}
	imap->time = 0;
}

void	player_animate(void *param)
{
	t_items	*imap;

	imap = (t_items *)param;
	imap->time += imap->mlx->delta_time;
	if (imap->time > 0.5)
		img_visibility(imap);
}
