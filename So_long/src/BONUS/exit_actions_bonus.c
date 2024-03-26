/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_actions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:43:20 by aidgomez          #+#    #+#             */
/*   Updated: 2024/02/27 19:03:11 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	game_success(t_items *imap)
{
	imap->success->instances[0].enabled = true;
	imap->exit->instances[0].enabled = false;
	imap->player->instances[0].enabled = false;
	imap->smile->instances[0].enabled = false;
	imap->bigsmile->instances[0].enabled = false;
	print_end_game("¡ YOU WIN SWEET TOOTH !");
	imap->lock_key = 1;
}
