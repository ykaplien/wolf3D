/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proccesing3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <ykaplien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 14:39:32 by ykaplien          #+#    #+#             */
/*   Updated: 2019/03/07 14:39:32 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	line_calculating(t_wolf *wolf, int x)
{
	int		variable;
	int		y;

	wolf->camera_x = wolf->dir_x + wolf->plane_x * wolf->camera_x;
	wolf->camera_y = wolf->dir_y + wolf->plane_y * wolf->camera_x;
	y = wolf->st_line_draw - 1;
	if (wolf->side == 0 && wolf->ray_dir_x > 0)
		variable = 0;
	else if (wolf->side == 0 && wolf->ray_dir_x < 0)
		variable = 1;
	else if (wolf->side == 1 && wolf->ray_dir_y > 0)
		variable = 2;
	else
		variable = 3;
	while (y < wolf->sp_line_draw)
	{
		line_calculating_ad(wolf, variable, y);
		y++;
		auxiliary(wolf, x, y);
	}
}

void	line_calculating_ad(t_wolf *wolf, int variable, int y)
{
	wolf->buff = y * 256 - WIN_Y * 128 + wolf->line_h * 128;
	wolf->text_y = ((wolf->buff * 64) / wolf->line_h) / 256;
	wolf->color.col = wolf->text[variable].addr[wolf->text_x * 4
		+ wolf->text_y * wolf->text[variable].sl + 2] << 16;
	wolf->color.col += wolf->text[variable].addr[wolf->text_x * 4
		+ wolf->text_y * wolf->text[variable].sl + 1] << 8;
	wolf->color.col += wolf->text[variable].addr[wolf->text_x * 4
		+ wolf->text_y * wolf->text[variable].sl];
	if (wolf->side == 1)
		wolf->color.col = (wolf->color.col >> 1) & 8355711;
}
