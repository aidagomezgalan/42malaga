/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:25:25 by aidgomez          #+#    #+#             */
/*   Updated: 2024/02/29 18:07:17 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//Size of img
# define PX 64

# include "../lib/libft/libft.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"

// Coordinates map
typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

// game items
typedef struct s_items
{
	char		**map;
	int			lock_key;
	int			player_moves;
	double		time;
	t_point		exit_pos;
	t_point		map_size;
	t_point		pj_pos;
	mlx_t		*mlx;
	mlx_image_t	*player;
	mlx_image_t	*smile;
	mlx_image_t	*bigsmile;
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*collect;
	mlx_image_t	*eated;
	mlx_image_t	*success;
	mlx_image_t	*exit;
}	t_items;

// map_checker.c
int		is_valid_map(char *str);

// map_checker_utils.c
int		is_wall(char *str);
int		is_path(char **str);
t_point	map_size(char **map);
int		items_count(char **map, char c);
t_point	item_axes(char **map, char c);

// msg.c
void	print_error(char *msg);
void	print_end_game(char *msg);
void	print_instructions_game(void);

// flood_fill.c
void	flood_fill(char **tab, t_point size, t_point begin);
char	**make_area(char **zone, t_point size);

// map_display.c
void	set_img(t_items *imap);
void	map_fill(t_items *imap);

// player_actions.c
void	player_update(t_items *imap, char key);
void	moves_count(t_items *imap);
void	player_animate(void *param);

// key_actions.c
void	key_a_moves(t_items *imap);
void	key_d_moves(t_items *imap);
void	key_w_moves(t_items *imap);
void	key_s_moves(t_items *imap);
void	key_action(mlx_key_data_t keydata, void *param);

// exit_actions.c
void	game_success(t_items *imap);

// collectable_actions.c
void	instances_img_visibility(mlx_image_t *img, int state);
int		are_collected(t_items *imap);
void	eating(t_items *imap);

#endif
