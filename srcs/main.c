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
		wolf = (t_wolf*)ft_memalloc(sizeof(t_wolf));
		data_work(wolf, argv[1]);
		init_mlx(wolf);
		print_map(wolf);
		mlx_loop(wolf->mlx_ptr);
	}
	else
		ft_usage();
	return (0);
}
