/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proccesing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <ykaplien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 19:47:52 by ykaplien          #+#    #+#             */
/*   Updated: 2019/03/01 19:47:52 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	draw(t_wolf *wolf)
{
	int		x;

	x = 0;
	ft_bzero(wolf->image, WIN_X * WIN_Y * 4);
	while (x < WIN_X)
	{
		var_calc(wolf, x);
		line_calculating(wolf, x);
		x++;
	}
	mlx_put_image_to_window(wolf->mlx_ptr, wolf->win_ptr, wolf->img_ptr, 0, 0);
}

void	dda(t_wolf *wolf)
{
	while (wolf->ray_hit == 0)
	{
		if (wolf->side_distance_x < wolf->side_distance_y)
		{
			wolf->side_distance_x = wolf->side_distance_x + wolf->distance_x;
			wolf->map_x = wolf->map_x + wolf->step_x;
			wolf->side = 0;
		}
		else
		{
			wolf->side_distance_y = wolf->side_distance_y + wolf->distance_y;
			wolf->map_y = wolf->map_y + wolf->step_y;
			wolf->side = 1;
		}
		if (wolf->map[wolf->map_x][wolf->map_y] > 0)
			wolf->ray_hit = 1;
	}
	dda_ad(wolf);
	line_draw_calc(wolf);
}

void	dda_ad(t_wolf *wolf)
{
	if (wolf->side == 0)
		wolf->perp_wall_dist = (wolf->map_x - wolf->pos_x +
			(1 - wolf->step_x) / 2) / wolf->ray_dir_x;
	else if (wolf->side == 1)
		wolf->perp_wall_dist = (wolf->map_y - wolf->pos_y +
			(1 - wolf->step_y) / 2) / wolf->ray_dir_y;
}

void	line_draw_calc(t_wolf *wolf)
{
	wolf->line_h = (int)(WIN_Y / wolf->perp_wall_dist);
	if ((wolf->st_line_draw = (((wolf->line_h) * (-1)) / 2) + WIN_Y / 2) < 0)
		wolf->st_line_draw = 0;
	if ((wolf->sp_line_draw = wolf->line_h / 2 + WIN_Y / 2) >= WIN_Y)
		wolf->sp_line_draw = WIN_Y - 1;
	if (wolf->side == 0)
		wolf->wall_x = wolf->pos_y + wolf->perp_wall_dist * wolf->ray_dir_y;
	else
		wolf->wall_x = wolf->pos_x + wolf->perp_wall_dist * wolf->ray_dir_x;
	hide(wolf);
}

void	hide(t_wolf *wolf)
{
	wolf->wall_x = wolf->wall_x - floor(wolf->wall_x);
	wolf->text_x = (int)(wolf->wall_x * (double)(64));
	if (wolf->side == 0 && wolf->ray_dir_x > 0)
		wolf->text_x = 64 - wolf->text_x - 1;
	if (wolf->side == 1 && wolf->ray_dir_y < 0)
		wolf->text_x = 64 - wolf->text_x - 1;
}
