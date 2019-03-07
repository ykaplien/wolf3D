/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <ykaplien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:01:10 by ykaplien          #+#    #+#             */
/*   Updated: 2019/02/26 16:01:11 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	check_walls(t_wolf *wolf, char *src)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (src[x] != '\0')
	{
		if (x / wolf->max_x == 0)
			if (src[x] == 48)
				invalid_map();
		if (x / wolf->max_x == wolf->max_y)
			if (src[x] == 48)
				invalid_map();
		x++;
	}
}

void	check_spawn(char *src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
		if (src[i++] == 48)
			return ;
	invalid_map();
}

void	data_fill(t_wolf *wolf, char *src)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	wolf->map = (int**)malloc(sizeof(int*) * wolf->max_y);
	while (y < wolf->max_y)
	{
		wolf->map[y] = (int*)malloc(sizeof(int) * wolf->max_x);
		y++;
	}
	y = 0;
	while (y < wolf->max_y)
	{
		x = 0;
		while (x < wolf->max_x)
		{
			wolf->map[y][x] = src[i] - 48;
			x++;
			i++;
		}
		i++;
		y++;
	}
}
