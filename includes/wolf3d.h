/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <ykaplien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:55:23 by ykaplien          #+#    #+#             */
/*   Updated: 2019/02/22 16:55:23 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# define WIN_X 1000
# define WIN_Y 800
# include "../libft/libft.h"
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

typedef struct			s_walls
{
	void				*img;
	char				*addr;
	int					bpp;
	int					sl;
	int					endl;
}						t_walls;

typedef struct	s_wolf
{
	int			dis_x;					// DRAW -> x planes of display
	int			max_x;					// DATA -> 
	int			max_y;					// DATA -> 
	int			**map;					// MAP -> 
	int			*image;					// MLX -> 
	int			bpp;					// MLX -> 
	int			size_line;				// MLX -> 
	int			endian;					// MLX -> 
	void		*mlx_ptr;				// MLX -> 
	void		*win_ptr;				// MLX -> 
	void		*window; 				// MLX -> 
	void		*img_ptr;				// MLX -> 
	double		old_dir_x;				// PLAYER -> old position of view ray
	double		old_plane_x;			// PLAYER -> PLAYER
	double		pos_x;					// PLAYER -> position of player
	double		pos_y;					// PLAYER -> position of player
	double		dir_x;					// PLAYER -> direction of view
	double		dir_y;					// PLAYER -> direction of view
	double		plane_x;				// PLAYER -> half of view port
	double		plane_y;				// PLAYER -> half of view port
	double		rot_a;					// PLAYER -> angle of rotation
	double		ray_dir_x;				// PLAYER -> direction of traicing ray
	double		ray_dir_y;				// PLAYER -> direction of traicing ray
	double		distance_x;				// PLAYER -> distance the ray has to travel to go from 1 x-side to the next x-side
	double		distance_y;				// PLAYER -> distance the ray has to travel to go from 1 y-side to the next y-side
	double		side_distance_x;		// PLAYER -> length of ray from current position to next x or y-side
	double		side_distance_y;		// PLAYER -> length of ray from current position to next x or y-side
	double		camera_x;				// PLAYER -> x-coordinate in camera space
	double		perp_wall_dist;			// DRAW -> distance of perpendicular ray
	int			line_h;
	int			st_line_draw;
	int			sp_line_draw;
	int			step_x;					// PLAYER -> distance of one step
	int			step_y;					// PLAYER -> distance of one step
	int			ray_hit;				//			
	int			side;
	int			map_x;					// PLAYER -> which box of the map we're in
	int			map_y;					// PLAYER -> which box of the map we're in
	t_walls		text[6];
}				t_wolf;

void			ft_usage(void);
void			check_x(t_wolf *wolf,int	x);
int				count_x(char *src);
void			data_work(t_wolf *wolf, char *src);
void			data_valid(t_wolf *wolf, char *src);
void			invalid_map(void);
void			check_symbols(char *src);
void			check_spawn(char *src);
void			check_walls(t_wolf *wolf, char *src);
void			data_fill(t_wolf *wolf, char *src);
void			print_map(t_wolf *wolf);
void			init_mlx(t_wolf *wolf);
void			init_vars(t_wolf *wolf);
void			init_textures(t_wolf *wolf);
int				esc(t_wolf *wolf);
void			find_pos(t_wolf *wolf);
void			move_forward(t_wolf *wolf);
void			move_backward(t_wolf *wolf);
void			look_left(t_wolf *wolf);
void			look_right(t_wolf *wolf);
void			redraw(t_wolf *wolf);
void			var_calc(t_wolf *wolf);
void			var_calc_additional(t_wolf *wolf);
void			dda(t_wolf *wolf);
void			line_draw_calc(t_wolf * wolf);
#endif