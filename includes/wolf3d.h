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
# define WIN_X 1200
# define WIN_Y 1080
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

typedef struct			s_rgb
{
	int					red;
	int					green;
	int					blue;
	int					col;
}						t_rgb;

typedef struct			s_wolf
{
	int					buff;
	int					dis_x;
	int					dis_y;
	int					max_x;
	int					max_y;
	int					**map;
	char				*image;
	int					bpp;
	int					size_line;
	int					endian;
	void				*mlx_ptr;
	void				*win_ptr;
	void				*window;
	void				*img_ptr;
	double				old_dir_x;
	double				old_plane_x;
	double				pos_x;
	double				pos_y;
	double				dir_x;
	double				dir_y;
	double				plane_x;
	double				plane_y;
	double				rot_a;
	double				ray_dir_x;
	double				ray_dir_y;
	double				distance_x;
	double				distance_y;
	double				side_distance_x;
	double				side_distance_y;
	double				camera_x;
	double				camera_y;
	double				perp_wall_dist;
	double				wall_x;
	double				step;
	int					line_h;
	int					st_line_draw;
	int					sp_line_draw;
	int					step_x;
	int					step_y;
	int					ray_hit;
	int					side;
	int					map_x;
	int					map_y;
	int					text_x;
	int					text_y;
	int					sound;
	t_walls				text[6];
	t_rgb				color;
}						t_wolf;

void					init_vars_ad(t_wolf *wolf);
void					sound(t_wolf *wolf);
void					init_mlx(t_wolf *wolf);
void					ft_usage(void);
void					check_x(t_wolf *wolf, int x);
int						count_x(char *src);
void					data_work(t_wolf *wolf, char *src);
void					data_valid(t_wolf *wolf, char *src);
void					invalid_map(void);
void					check_symbols(char *src);
void					check_spawn(char *src);
void					check_walls(t_wolf *wolf, char *src);
void					data_fill(t_wolf *wolf, char *src);
void					init_mlx(t_wolf *wolf);
void					init_vars(t_wolf *wolf);
void					init_textures(t_wolf *wolf);
int						esc(t_wolf *wolf);
void					find_pos(t_wolf *wolf);
void					move_forward(t_wolf *wolf);
void					move_backward(t_wolf *wolf);
void					look_left(t_wolf *wolfv);
void					look_right(t_wolf *wolfv);
void					redraw(t_wolf *wolf);
void					var_calc(t_wolf *wolf, int x);
void					var_calc_additionalx(t_wolf *wolf);
void					var_calc_additionaly(t_wolf *wolf);
void					dda(t_wolf *wolf);
void					line_draw_calc(t_wolf *wolf);
void					draw(t_wolf *wolf);
void					hide(t_wolf *wolf);
void					line_calculating(t_wolf *wolf, int x);
void					line_calculating_ad(t_wolf *wolf, int variable, int y);
void					auxiliary(t_wolf *wolf, int x, int y);
int						event_handle(int key, t_wolf *wolf);
void					dda_ad(t_wolf *wolf);

#endif
