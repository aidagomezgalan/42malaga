/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_actions_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:30:08 by aidgomez          #+#    #+#             */
/*   Updated: 2024/02/29 17:43:23 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	moves_display(t_items *imap)
{
	char	*count;

	count = ft_itoa(imap->player_moves);
	if (!count)
		return ;
	mlx_delete_image(imap->mlx, imap->display_moves);
	imap->display_moves = mlx_put_string(imap->mlx, count, PX / 3, PX / 3);
	free(count);
}

void	moves_count(t_items *imap)
{
	imap->player_moves++;
	ft_printf("Player moves: %i\n", imap->player_moves);
	moves_display(imap);
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
