/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:19:57 by aidgomez          #+#    #+#             */
/*   Updated: 2024/02/29 14:23:11 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_a_moves(t_items *imap)
{
	int	prev;
	int	exit_x;
	int	exit_y;

	exit_x = imap->exit_pos.x;
	exit_y = imap->exit_pos.y;
	imap->pj_pos = item_axes(imap->map, 'P');
	prev = imap->pj_pos.x - 1;
	if (imap->map[imap->pj_pos.y][prev] != '1')
	{
		player_update(imap, 'a');
		if (imap->map[imap->pj_pos.y][prev] == 'C')
			eating(imap);
		else if (imap->pj_pos.y == exit_y && prev == exit_x
			&& are_collected(imap))
			game_success(imap);
		imap->map[imap->pj_pos.y][prev] = 'P';
		imap->map[imap->pj_pos.y][imap->pj_pos.x] = '0';
	}
}

void	key_d_moves(t_items *imap)
{
	int	next;
	int	exit_x;
	int	exit_y;

	exit_x = imap->exit_pos.x;
	exit_y = imap->exit_pos.y;
	imap->pj_pos = item_axes(imap->map, 'P');
	next = imap->pj_pos.x + 1;
	if (imap->map[imap->pj_pos.y][next] != '1')
	{
		player_update(imap, 'd');
		if (imap->map[imap->pj_pos.y][next] == 'C')
			eating(imap);
		else if (imap->pj_pos.y == exit_y && next == exit_x
			&& are_collected(imap))
			game_success(imap);
		imap->map[imap->pj_pos.y][next] = 'P';
		imap->map[imap->pj_pos.y][imap->pj_pos.x] = '0';
	}
}

void	key_w_moves(t_items *imap)
{
	int	prev;
	int	exit_x;
	int	exit_y;

	exit_x = imap->exit_pos.x;
	exit_y = imap->exit_pos.y;
	imap->pj_pos = item_axes(imap->map, 'P');
	prev = imap->pj_pos.y - 1;
	if (imap->map[prev][imap->pj_pos.x] != '1')
	{
		player_update(imap, 'w');
		if (imap->map[prev][imap->pj_pos.x] == 'C')
			eating(imap);
		else if (prev == exit_y && imap->pj_pos.x == exit_x
			&& are_collected(imap))
			game_success(imap);
		imap->map[prev][imap->pj_pos.x] = 'P';
		imap->map[imap->pj_pos.y][imap->pj_pos.x] = '0';
	}
}

void	key_s_moves(t_items *imap)
{
	int	next;
	int	exit_x;
	int	exit_y;

	exit_x = imap->exit_pos.x;
	exit_y = imap->exit_pos.y;
	imap->pj_pos = item_axes(imap->map, 'P');
	next = imap->pj_pos.y + 1;
	if (imap->map[next][imap->pj_pos.x] != '1')
	{
		player_update(imap, 's');
		if (imap->map[next][imap->pj_pos.x] == 'C')
			eating(imap);
		else if (next == exit_y && imap->pj_pos.x == exit_x
			&& are_collected(imap))
			game_success(imap);
		imap->map[next][imap->pj_pos.x] = 'P';
		imap->map[imap->pj_pos.y][imap->pj_pos.x] = '0';
	}
}

void	key_action(mlx_key_data_t keydata, void *param)
{
	t_items	*imap;

	imap = (t_items *)param;
	if (imap->lock_key == 0)
	{
		if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
			key_a_moves(imap);
		if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
			key_d_moves(imap);
		if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
			key_w_moves(imap);
		if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
			key_s_moves(imap);
	}
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		mlx_close_window(imap->mlx);
}
