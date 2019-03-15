/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floorcel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <ykaplien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 15:08:40 by ykaplien          #+#    #+#             */
/*   Updated: 2019/03/15 15:08:41 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	floor_ceiling(t_wolf *wolf, int x)
{
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
	current_floor_pos[0] = current_dist / wolf->perp_wall_dist *
	wolf->floor_pos_x + (1.0 - (current_dist / wolf->perp_wall_dist))
	* wolf->pos_x;
	current_floor_pos[1] = current_dist / wolf->perp_wall_dist *
	wolf->floor_pos_y + (1.0 - (current_dist / wolf->perp_wall_dist))
	* wolf->pos_y;
	wolf->floor_t_x = (int)(current_floor_pos[0] * 64) % 64;
	wolf->floor_t_y = (int)(current_floor_pos[1] * 64) % 64;
	put_floor(wolf, x, ver_pix);
	put_ceiling(wolf, x, WIN_Y - ver_pix);
}

void	floor_def(t_wolf *e)
{
	if (e->side == 0)
	{
		if (e->ray_dir_x > 0)
		{
			e->floor_pos_x = (double)e->map_x;
			e->floor_pos_y = (double)e->map_y + e->wall_x;
		}
		else if (e->ray_dir_x < 0)
		{
			e->floor_pos_x = (double)e->map_x + 1.0;
			e->floor_pos_y = (double)e->map_y + e->wall_x;
		}
	}
	else if (e->side == 1 && e->ray_dir_y > 0)
	{
		e->floor_pos_x = (double)e->map_x + e->wall_x;
		e->floor_pos_y = (double)e->map_y;
	}
	else
	{
		e->floor_pos_x = (double)e->map_x + e->wall_x;
		e->floor_pos_y = (double)e->map_y + 1.0;
	}
}

void	put_floor(t_wolf *wolf, int x, int y)
{
	int		pixels;

	pixels = (x * 4) + ((4 * WIN_X) * y);
	wolf->image[pixels] = wolf->text[4].addr[4 *
		(64 * wolf->floor_t_y + wolf->floor_t_x)];
	wolf->image[pixels + 1] = wolf->text[4].addr[4 *
		(64 * wolf->floor_t_y + wolf->floor_t_x) + 1];
	wolf->image[pixels + 2] = wolf->text[4].addr[4 *
		(64 * wolf->floor_t_y + wolf->floor_t_x) + 2];
}

void	put_ceiling(t_wolf *wolf, int x, int y)
{
	int		pixels;

	pixels = (x * 4) + ((4 * WIN_X) * y);
	wolf->image[pixels] = wolf->text[5].addr[4 *
		(64 * wolf->floor_t_y + wolf->floor_t_x)];
	wolf->image[pixels + 1] = wolf->text[5].addr[4 *
		(64 * wolf->floor_t_y + wolf->floor_t_x) + 1];
	wolf->image[pixels + 2] = wolf->text[5].addr[4 *
		(64 * wolf->floor_t_y + wolf->floor_t_x) + 2];
}
