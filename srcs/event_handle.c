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

int		event_handle(int key, t_wolf *wolf)
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
	else if (key == 46)
		sound(wolf);
	draw(wolf);
	return (0);
}

void	move_forward(t_wolf *a)
{
	if (a->map[(int)(a->pos_x + a->dir_x * (a->step + 0.2345))]
		[(int)(a->pos_y)] == 0)
		a->pos_x += a->dir_x * a->step;
	if (a->map[(int)(a->pos_x)]
		[(int)(a->pos_y + a->dir_y * (a->step + 0.2345))] == 0)
		a->pos_y += a->dir_y * a->step;
}

void	move_backward(t_wolf *a)
{
	if (a->map[(int)(a->pos_x - (a->dir_x * a->step + 0.2345))]
		[(int)(a->pos_y)] == 0)
		a->pos_x -= a->dir_x * a->step;
	if (a->map[(int)(a->pos_x)]
		[(int)(a->pos_y - a->dir_y * (a->step + 0.2345))] == 0)
		a->pos_y -= a->dir_y * a->step;
}

void	look_left(t_wolf *a)
{
	double		tmp;

	a->old_dir_x = a->dir_x;
	a->dir_x = a->dir_x * cos(-(a->rot_a)) - a->dir_y * sin(-(a->rot_a));
	a->dir_y = a->old_dir_x * sin(-(a->rot_a)) + a->dir_y * cos(-(a->rot_a));
	a->old_plane_x = a->plane_x;
	a->plane_x = a->plane_x * cos(-(a->rot_a)) - a->plane_y * sin(-(a->rot_a));
	tmp = a->old_plane_x * sin(-(a->rot_a));
	a->plane_y = tmp + a->plane_y * cos(-(a->rot_a));
}

void	look_right(t_wolf *a)
{
	a->old_dir_x = a->dir_x;
	a->dir_x = a->dir_x * cos(a->rot_a) - a->dir_y * sin(a->rot_a);
	a->dir_y = a->old_dir_x * sin(a->rot_a) + a->dir_y * cos(a->rot_a);
	a->old_plane_x = a->plane_x;
	a->plane_x = a->plane_x * cos(a->rot_a) - a->plane_y * sin(a->rot_a);
	a->plane_y = a->old_plane_x * sin(a->rot_a) + a->plane_y * cos(a->rot_a);
}
