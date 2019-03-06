/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proccesing2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <ykaplien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 15:33:46 by ykaplien          #+#    #+#             */
/*   Updated: 2019/03/06 15:33:46 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	auxiliary(t_wolf *wolf, int pos)
{
	wolf->image[pos] = wolf->color.col & 0x0000ff;
	wolf->image[pos + 1] = (wolf->color.col >> 8) & 0xff;
	wolf->image[pos + 2] = (wolf->color.col >> 16);
}

int		pix_calc(t_wolf *wolf)
{
	int		res;

	res = 0;
	res = (wolf->dis_x * 4) + ((WIN_X * 4) * wolf->dis_y);
	return (res);
}
