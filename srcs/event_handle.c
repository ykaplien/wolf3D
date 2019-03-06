/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <ykaplien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 17:30:02 by ykaplien          #+#    #+#             */
/*   Updated: 2019/02/27 17:30:02 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		event_handle(t_wolf *wolf, int key)
{

	if (key == 53)
		esc(wolf);
	else if (key == 123)
		look_left(wolf);
	else if (key == 124)
		look_right(wolf);
	else if (key == 125)
		move_backward(wolf);
	else if (key == 126)
		move_forward(wolf);
	draw(wolf);
	return (0);
}

void	move_forward(t_wolf *wolf)
{
	if (wolf->map[(int)(wolf->pos_x + wolf->dir_x * (wolf->step + 0.2))][(int)(wolf->pos_y)] == 0)
		wolf->pos_x += wolf->dir_x * wolf->step;
	if (wolf->map[(int)(wolf->pos_x)][(int)(wolf->pos_y + wolf->dir_y * (wolf->step + 0.2))] == 0)
		wolf->pos_y += wolf->dir_y * wolf->step;
}

void	move_backward(t_wolf *wolf)
{
	if (wolf->map[(int)(wolf->pos_x - (wolf->dir_x * wolf->step + 0.2))][(int)(wolf->pos_y)] == 0)
			wolf->pos_x -= wolf->dir_x * wolf->step;
	if (wolf->map[(int)(wolf->pos_x)][(int)(wolf->pos_y - wolf->dir_y * (wolf->step + 0.2))] == 0)
		wolf->pos_y -= wolf->dir_y * wolf->step;
}

void	look_left(t_wolf *wolf)
{
	wolf->old_dir_x = wolf->dir_x;
	wolf->dir_x = wolf->dir_x * cos(-(wolf->rot_a)) - wolf->dir_y * sin(-(wolf->rot_a));
	wolf->dir_y = wolf->old_dir_x * sin(-(wolf->rot_a)) + wolf->dir_y * cos(-(wolf->rot_a));
	wolf->old_plane_x = wolf->plane_x;
	wolf->plane_x = wolf->plane_x * cos(-(wolf->rot_a)) - wolf->plane_y * sin(-(wolf->rot_a));
	wolf->plane_y = wolf->old_plane_x * sin(-(wolf->rot_a)) + wolf->plane_y * cos(-(wolf->rot_a));
}

void	look_right(t_wolf *wolf)
{
	wolf->old_dir_x = wolf->dir_x;
	wolf->dir_x = wolf->dir_x * cos(wolf->rot_a) - wolf->dir_y * sin(wolf->rot_a);
	wolf->dir_y = wolf->old_dir_x * sin(wolf->rot_a) + wolf->dir_y * cos(wolf->rot_a);
	wolf->old_plane_x = wolf->plane_x;
	wolf->plane_x = wolf->plane_x * cos(wolf->rot_a) - wolf->plane_y * sin(wolf->rot_a);
	wolf->plane_y = wolf->old_plane_x * sin(wolf->rot_a) + wolf->plane_y * cos(wolf->rot_a);
}