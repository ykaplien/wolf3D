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

void	draw(t_wolf *wolf)
{
	wolf->dis_x = 0;
	ft_bzero(wolf->image, WIN_X * WIN_Y * 4);
	while (wolf->dis_x < WIN_X)
	{
		var_calc(wolf, x);

		wolf->dis_x++;
	}
}

void	dda(t_wolf *wolf)
{
	while (wolf->ray_hit == 0)
	{
		if (wolf->side_distance_x < side_distance_y)
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
		if (wolf->map[wolf->map_x][map_y] > 0)
			wolf->ray_hit = 1;
	}
	if (wolf->side == 0)
		wolf->perp_wall_dist = (wolf->map_x - wolf->pos_x + ( 1 - wolf->step_x) / 2) / wolf->ray_dir_x;
	else if (wolf->side == 1)
		wolf->perp_wall_dist = (wolf->map_y - wolf->pos_y + ( 1 - wolf->step_y) / 2) / wolf->ray_dir_y;
	more_calc(wolf);
}

void	line_draw_calc(t_wolf * wolf)
{
	wolf->line_h = (int)(WIN_X / wolf->perp_wall_dist);
	// if ((wolf->st_line_draw = ((wolf->line_h * -1) / 2) + WIN_X / 2) < 0)      !!!ПЕРЕПРОВЕРИТЬ!!!
	// 	wolf->st_line_draw = 0;
	// if ((wolf->sp_line_draw = ((wolf->line_h * -1 / 2) + WIN_X / 2) >=  WIN_Y)
	// 	wolf->sp_line_draw = WIN_X - 1;
}