/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_display_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:51:09 by aidgomez          #+#    #+#             */
/*   Updated: 2024/02/29 14:26:20 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

mlx_image_t	*create_img(t_items *imap, char *img)
{
	mlx_texture_t	*texture;
	mlx_image_t		*item;
	char			*path;

	path = ft_strjoin("./images/", img);
	texture = mlx_load_png(path);
	free(path);
	if (!texture)
		return (0);
	item = mlx_texture_to_image(imap->mlx, texture);
	mlx_delete_texture(texture);
	if (!item)
		return (0);
	return (item);
}

void	set_img(t_items *imap)
{
	imap->wall = create_img(imap, "wall.png");
	imap->player = create_img(imap, "player.png");
	imap->smile = create_img(imap, "smile.png");
	imap->bigsmile = create_img(imap, "bigsmile.png");
	imap->floor = create_img(imap, "floor.png");
	imap->collect = create_img(imap, "collect.png");
	imap->eated = create_img(imap, "eated.png");
	imap->success = create_img(imap, "success.png");
	imap->exit = create_img(imap, "exit.png");
	imap->enemy = create_img(imap, "enemy.png");
	imap->died = create_img(imap, "died.png");
}

void	img_display(t_items *imap, mlx_image_t *item, char c)
{
	int		i;
	int		j;
	int32_t	img;

	i = 0;
	if (!imap || !item || !c)
		return ;
	while (imap->map[i])
	{
		j = 0;
		while (imap->map[i][j])
		{
			if (imap->map[i][j] == c)
				img = mlx_image_to_window(imap->mlx, item, j * PX, i * PX);
			if (img < 0)
				return ;
			j++;
		}
		i++;
	}
}

void	floor_display(t_items *imap, mlx_image_t *item)
{
	int		i;
	int		j;
	int32_t	img;

	i = 0;
	if (!imap || !item)
		return ;
	while (imap->map[i])
	{
		j = 0;
		while (imap->map[i][j])
		{
			img = mlx_image_to_window(imap->mlx, item, j * PX, i * PX);
			if (img < 0)
				return ;
			j++;
		}
		i++;
	}
}

void	map_fill(t_items *imap)
{
	floor_display(imap, imap->floor);
	img_display(imap, imap->wall, '1');
	img_display(imap, imap->eated, 'C');
	img_display(imap, imap->collect, 'C');
	img_display(imap, imap->success, 'E');
	img_display(imap, imap->exit, 'E');
	img_display(imap, imap->died, 'X');
	img_display(imap, imap->enemy, 'X');
	img_display(imap, imap->bigsmile, 'P');
	img_display(imap, imap->smile, 'P');
	img_display(imap, imap->player, 'P');
	instances_img_visibility(imap->died, false);
	instances_img_visibility(imap->eated, false);
}
