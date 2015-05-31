/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 14:53:58 by aaudiber          #+#    #+#             */
/*   Updated: 2015/05/03 23:02:43 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"
#include "get_next_line/get_next_line.h"

static void		init_brick_type(int type, t_brick *brick)
{
	brick->type = type;
	brick->resistance = 1;
	brick->destructible = 1;
	if (type == BRICK_HARD)
		brick->resistance = 3;
	else if (type == BRICK_UNDESTRUCTIBLE)
		brick->destructible = 0;
	brick->destructed = 0;
}

static void		enter_bricks(t_map *map, char **data, int i)
{
	int		ct;
	char	**tmp;
	int		j;

	ct = 0;
	j = 0;
	while (ct < map->nb_bricks)
	{
		tmp = ft_strsplit(data[i], ' ');
		init_brick_type(ft_atoi(tmp[j]), map->bricks + ct);
		j++;
		map->bricks[ct].x = ft_atoi(tmp[j]);
		j++;
		map->bricks[ct].y = ft_atoi(tmp[j]);
		j++;
		map->bricks[ct].height = ft_atoi(tmp[j]);
		j++;
		map->bricks[ct].width = ft_atoi(tmp[j]);
		j = 0;
		i++;
		ct++;
		free(tmp);
	}
}

static void		set_map(t_map *map, char **data)
{
	int i;

	i = 0;
	map->width = ft_atoi(data[i]);
	i++;
	map->height = ft_atoi(data[i]);
	i++;
	map->col_in_f = 2.0f / map->width;
	map->row_in_f = 2.0f / map->height;
	map->nb_bricks = ft_atoi(data[i]);
	i++;
	map->bricks = (t_brick*)malloc(sizeof(t_brick) * map->nb_bricks);
	enter_bricks(map, data, i);
}

static char		**get_map(char *path, int size)
{
	int		i;
	int		fd;
	char	*line;
	char	**ret;

	i = 0;
	ret = (char**)malloc(sizeof(char*) * size);
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		ret[i] = line;
		i++;
	}
	return (ret);
}

t_map			*create_map(char *path)
{
	t_map	*map;
	char	*line;
	char	**data;
	int		fd;
	int		i;

	i = 0;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
		i++;
	data = get_map(path, i);
	i = 0;
	map = (t_map*)malloc(sizeof(t_map));
	set_map(map, data);
	return (map);
}
