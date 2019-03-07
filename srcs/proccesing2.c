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

void	auxiliary(t_wolf *wolf, int x, int y)
{
	int		pos;

	pos = 0;
	pos = (x * 4) + ((4 * WIN_X) * y);
	wolf->image[pos] = wolf->color.col & 0x0000ff;
	wolf->image[pos + 1] = (wolf->color.col >> 8) & 0xff;
	wolf->image[pos + 2] = (wolf->color.col >> 16);
}
