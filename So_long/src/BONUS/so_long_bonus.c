/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:38:02 by aidgomez          #+#    #+#             */
/*   Updated: 2024/02/29 20:10:06 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_items	*imap_init(char *str)
{
	t_items	*imap;
	int		width;
	int		height;

	imap = malloc(sizeof(t_items));
	if (!imap)
		return (0);
	imap->map = fd_to_array(str);
	imap->map_size = map_size(imap->map);
	imap->player_moves = 0;
	imap->lock_key = 0;
	imap->exit_pos = item_axes(imap->map, 'E');
	width = PX * imap->map_size.x;
	height = PX * imap->map_size.y;
	imap->mlx = mlx_init(width, height, "Pespinos's Game", false);
	set_img(imap);
	return (imap);
}

void	imap_free(t_items *imap)
{
	memory_str_free(imap->map);
	free(imap);
}

int32_t	start_game(char *str)
{
	t_items	*imap;

	imap = imap_init(str);
	if (!imap)
		return (EXIT_FAILURE);
	map_fill(imap);
	mlx_key_hook(imap->mlx, &key_action, imap);
	mlx_loop_hook(imap->mlx, &player_animate, imap);
	print_instructions_game();
	mlx_loop(imap->mlx);
	mlx_terminate(imap->mlx);
	imap_free(imap);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!is_valid_map(argv[1]))
			print_error("Mapa no válido");
		else
			start_game(argv[1]);
	}
	else
		print_error("Se necesita un mapa para jugar");
	return (0);
}
