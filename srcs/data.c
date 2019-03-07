/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <ykaplien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 18:41:30 by ykaplien          #+#    #+#             */
/*   Updated: 2019/02/22 18:41:31 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	data_work(t_wolf *wolf, char *src)
{
	int		fd;
	char	*line;
	char	*tmp_map;

	tmp_map = ft_strnew(1);
	line = NULL;
	fd = open(src, O_RDONLY);
	if (fd < 0)
		ft_usage();
	while (get_next_line(fd, &line) > 0)
	{
		check_x(wolf, count_x(line));
		tmp_map = ft_strjoinfree(tmp_map, line, 3);
		tmp_map = ft_strjoinfree(tmp_map, "\n", 1);
		wolf->max_y++;
	}
	data_valid(wolf, tmp_map);
}

void	check_x(t_wolf *wolf, int x)
{
	if (wolf->max_x == 0)
		wolf->max_x = x;
	else
	{
		if (wolf->max_x != x)
			invalid_map();
	}
}

int		count_x(char *src)
{
	int		i;

	i = 0;
	while (src[i])
		i++;
	if (src[0] == 48 || src[i - 1] == 48)
		invalid_map();
	return (i);
}

void	data_valid(t_wolf *wolf, char *src)
{
	check_symbols(src);
	check_walls(wolf, src);
	check_spawn(src);
	data_fill(wolf, src);
}

void	check_symbols(char *src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		if ((src[i] >= 48 && src[i] <= 57) || src[i] == '\n')
			;
		else
			invalid_map();
		i++;
	}
}
