/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <ykaplien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 18:40:06 by ykaplien          #+#    #+#             */
/*   Updated: 2019/02/22 18:40:07 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	ft_usage(void)
{
	ft_putstr("usage: ./wolf3d <map>\nexample: ./wolf3d map\n");
	exit(1);
}

void	invalid_map(void)
{
	ft_putstr("invalid map\n");
	exit(1);
}

void	init_vars(t_wolf *wolf)
{
	int		width;
	int		heigth;

	wolf->text[0].img = mlx_xpm_file_to_image(wolf->mlx_ptr,
		"./imgs/texture0.xpm", &width, &heigth);
	wolf->text[1].img = mlx_xpm_file_to_image(wolf->mlx_ptr,
		"./imgs/texture1.xpm", &width, &heigth);
	wolf->text[2].img = mlx_xpm_file_to_image(wolf->mlx_ptr,
		"./imgs/texture2.xpm", &width, &heigth);
	wolf->text[3].img = mlx_xpm_file_to_image(wolf->mlx_ptr,
		"./imgs/texture3.xpm", &width, &heigth);
	wolf->text[4].img = mlx_xpm_file_to_image(wolf->mlx_ptr,
		"./imgs/texture4.xpm", &width, &heigth);
	wolf->text[5].img = mlx_xpm_file_to_image(wolf->mlx_ptr,
		"./imgs/texture5.xpm", &width, &heigth);
	wolf->dir_x = 1;
	wolf->dir_y = 0;
	wolf->plane_x = 0;
	wolf->plane_y = 0.66;
	wolf->step = 0.35;
	wolf->rot_a = 0.09;
	init_textures(wolf);
}

void	init_textures(t_wolf *wolf)
{
	wolf->text[0].addr = mlx_get_data_addr(wolf->text[0].img, 
		&wolf->text[0].bpp, &wolf->text[0].sl, &wolf->text[0].endl);
	wolf->text[1].addr = mlx_get_data_addr(wolf->text[1].img, 
		&wolf->text[1].bpp, &wolf->text[1].sl, &wolf->text[1].endl);
	wolf->text[2].addr = mlx_get_data_addr(wolf->text[2].img, 
		&wolf->text[2].bpp, &wolf->text[2].sl, &wolf->text[2].endl);
	wolf->text[3].addr = mlx_get_data_addr(wolf->text[3].img, 
		&wolf->text[3].bpp, &wolf->text[3].sl, &wolf->text[3].endl);
	wolf->text[4].addr = mlx_get_data_addr(wolf->text[4].img, 
		&wolf->text[4].bpp, &wolf->text[4].sl, &wolf->text[4].endl);
	wolf->text[5].addr = mlx_get_data_addr(wolf->text[5].img, 
		&wolf->text[5].bpp, &wolf->text[5].sl, &wolf->text[5].endl);
}

int		esc(t_wolf *wolf)
{
	mlx_destroy_window(wolf->mlx_ptr, wolf->win_ptr);
	free(wolf);
	exit(0);
	return (0);
}