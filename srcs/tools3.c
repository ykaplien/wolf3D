/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <ykaplien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 15:35:28 by ykaplien          #+#    #+#             */
/*   Updated: 2019/03/07 15:35:29 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	init_vars_ad(t_wolf *wolf)
{
	wolf->dir_x = 1;
	wolf->step = 0.5;
	wolf->plane_x = 0;
	wolf->dir_y = 0;
	wolf->rot_a = 0.09;
	wolf->plane_y = 0.66;
	find_pos(wolf);
	init_textures(wolf);
}
