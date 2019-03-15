/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <ykaplien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:53:51 by ykaplien          #+#    #+#             */
/*   Updated: 2019/02/22 16:53:52 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		main(int argc, char **argv)
{
	t_wolf		*wolf;

	if (argc == 2)
	{
		wolf = (t_wolf*)malloc(sizeof(t_wolf));
		bzero(wolf, sizeof(t_wolf));
		data_work(wolf, argv[1]);
		init_mlx(wolf);
		draw(wolf);
		mlx_hook(wolf->win_ptr, 17, 1L << 17, esc, wolf);
		mlx_hook(wolf->win_ptr, 2, 5, event_handle, wolf);
		sound(wolf);
		mlx_loop(wolf->mlx_ptr);
	}
	else
		ft_usage();
	return (0);
}

void	init_mlx(t_wolf *wolf)
{
	wolf->mlx_ptr = mlx_init();
	wolf->win_ptr = mlx_new_window(wolf->mlx_ptr, WIN_X, WIN_Y, "Wolf3D");
	wolf->img_ptr = mlx_new_image(wolf->mlx_ptr, WIN_X, WIN_Y);
	wolf->image = mlx_get_data_addr(wolf->img_ptr, &(wolf->bpp),
		&(wolf->size_line), &(wolf->endian));
	init_vars(wolf);
}
