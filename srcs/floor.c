/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <ykaplien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 15:55:12 by ykaplien          #+#    #+#             */
/*   Updated: 2019/03/12 15:55:13 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	floor_ceiling(t_wolf *wolf, int x)
{
	// double	cur_floor_pos[2];
	int		ver_pix;

	wolf->sp_line_draw = (wolf->sp_line_draw < 0) ? WIN_Y : wolf->sp_line_draw;
	ver_pix = wolf->sp_line_draw + 1;
	floor_def(wolf);
	while (ver_pix < WIN_Y)
	{
		floor_ceiling_calc(wolf, ver_pix, x);
		ver_pix++;
	}
}

void	floor_ceiling_calc(t_wolf *wolf, int ver_pix, int x)
{
	double	current_dist;
	double	current_floor_pos[2];

	current_dist = WIN_Y / (2.0 * ver_pix - WIN_Y);
	current_floor_pos[0] = current_dist / wolf->perp_wall_dist * wolf->floor_pos_x + (1.0 - (current_dist / wolf->perp_wall_dist)) * wolf->pos_x;
	current_floor_pos[1] = current_dist / wolf->perp_wall_dist * wolf->floor_pos_y + (1.0 - (current_dist / wolf->perp_wall_dist)) * wolf->pos_y;
	wolf->floor_t_x = (int)(current_floor_pos[0] * 64) % 64;
	wolf->floor_t_y = (int)(current_floor_pos[1] * 64) % 64;
	put_floor(wolf, x, ver_pix);
	put_ceiling(wolf, x, WIN_Y - ver_pix);
}

void	put_floor(t_wolf *wolf, int x, int y)
{
	int		pixels;

	pixels = (x * 4) + ((WIN_X * 4) * y);
	wolf->image[pixels] = wolf->text[4].addr[4 * (64 * wolf->floor_t_y + wolf->floor_t_x)];
	wolf->image[pixels + 1] = wolf->text[4].addr[4 * (64 * wolf->floor_t_y + wolf->floor_t_x) + 1];
	wolf->image[pixels + 2] = wolf->text[4].addr[4 * (64 * wolf->floor_t_y + wolf->floor_t_x) + 2];
}

void	put_ceiling(t_wolf *wolf, int x, int y)
{
	int		pixels;

	pixels = (x * 4) + ((WIN_X * 4) * y);
	wolf->image[pixels] = wolf->text[5].addr[4 * (64 * wolf->floor_t_y + wolf->floor_t_x)];
	wolf->image[pixels + 1] = wolf->text[5].addr[4 * (64 * wolf->floor_t_y + wolf->floor_t_x) + 1];
	wolf->image[pixels + 2] = wolf->text[5].addr[4 * (64 * wolf->floor_t_y + wolf->floor_t_x) + 2];
}

void	floor_def(t_wolf *wolf)
{
	if (wolf->side == 0)
	{
		if (wolf->ray_dir_x < 0)
		{
			wolf->floor_pos_y = (double)wolf->map_y + wolf->wall_x;
			wolf->floor_pos_x = (double)wolf->map_x;
		}
		else if (wolf->ray_dir_x > 0)
		{
			wolf->floor_pos_y = (double)wolf->map_y + wolf->wall_x;
			wolf->floor_pos_x = (double)wolf->map_x + 1.0;
		}
	}
	else if (wolf->side == 1 && wolf->ray_dir_y > 0)
	{
		wolf->floor_pos_y = (double)wolf->map_y;
		wolf->floor_pos_x = (double)wolf->map_x + wolf->wall_x;
	}
	else
	{
		wolf->floor_pos_y = (double)wolf->map_y + 1.0;
		wolf->floor_pos_x = (double)wolf->map_x + wolf->wall_x;
	}
}
