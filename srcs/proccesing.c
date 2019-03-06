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
	printf("%s\n", "OK1");
	wolf->dis_x = 0;
	printf("%s\n", "OK2");
	ft_bzero(wolf->image, WIN_X * WIN_Y * 4);
	while (wolf->dis_x < WIN_X)
	{
		var_calc(wolf);
		
		wolf->dis_x++;
	}
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
	if (wolf->side == 0)
		wolf->perp_wall_dist = (wolf->map_x - wolf->pos_x + ( 1 - wolf->step_x) / 2) / wolf->ray_dir_x;
	else if (wolf->side == 1)
		wolf->perp_wall_dist = (wolf->map_y - wolf->pos_y + ( 1 - wolf->step_y) / 2) / wolf->ray_dir_y;
	line_draw_calc(wolf);
}

void	line_draw_calc(t_wolf * wolf)
{
	wolf->line_h = (int)(WIN_X / wolf->perp_wall_dist);
	if ((wolf->st_line_draw = (((wolf->line_h) * (-1)) / 2) + WIN_Y / 2) < 0)
		wolf->st_line_draw = 0;
	if ((wolf->sp_line_draw = wolf->line_h / 2 + WIN_Y / 2) >= WIN_Y)
		wolf->sp_line_draw = WIN_Y - 1;
	if (wolf->side == 0)
		wolf->wall_x = wolf->pos_y + wolf->perp_wall_dist * wolf->ray_dir_y;
	else
		wolf->wall_x = wolf->pos_x + wolf->perp_wall_dist * wolf->ray_dir_y;
	wolf->wall_x = wolf->wall_x - floor(wolf->wall_x);
	wolf->text_x = (int)(wolf->wall_x * (double)(64));
	hide(wolf);
}

void	hide(t_wolf *wolf)
{
	if (wolf->side == 0 && wolf->ray_dir_x > 0)
		wolf->text_x = 64 - wolf->text_x - 1;
	if (wolf->side == 1 && wolf->ray_dir_y < 0)
		wolf->text_x = 64 - wolf->text_x - 1;
	line_calculating(wolf);
}

void	line_calculating(t_wolf *wolf)
{
	int		variable;

	wolf->camera_x = wolf->dir_x + wolf->plane_x * wolf->camera_x;
	wolf->camera_y = wolf->dir_y + wolf->plane_y * wolf->camera_x;
	wolf->dis_y = wolf->st_line_draw - 1;
	if (wolf->side == 0 && wolf->camera_x)
		variable = 0;
	else if (wolf->side == 0 && wolf->camera_x < 0)
		variable = 1;
	else if (wolf->side == 1 && wolf->camera_y >= 0)
		variable = 2;
	else
		variable = 3;
	while (wolf->dis_y < wolf->sp_line_draw)
	{
		wolf->buff = wolf->dis_y * 256 - WIN_Y * 128 + wolf->line_h * 128;
		wolf->text_y = ((wolf->buff * 64) / wolf->line_h) / 256;
		wolf->color.col = wolf->text[variable].addr[wolf->text_x * 4 + wolf->text_y * wolf->text[variable].sl + 2] << 16;
		wolf->color.col += wolf->text[variable].addr[wolf->text_x * 4 + wolf->text_y * wolf->text[variable].sl + 1] << 8;
		wolf->color.col += wolf->text[variable].addr[wolf->text_x * 4 + wolf->text_y * wolf->text[variable].sl];
		if (wolf->side == 1)
			wolf->color.col = (wolf->color.col >> 1) & 8355711;
		wolf->dis_y++;
		auxiliary(wolf, pix_calc(wolf));
	}
}