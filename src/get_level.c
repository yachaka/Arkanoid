/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_level.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 18:44:50 by aaudiber          #+#    #+#             */
/*   Updated: 2015/05/03 22:49:12 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void		load_level(t_game *game)
{
	char	*level;

	level = get_level("levels/", game->level);
	if (!level)
	{
		win_game(game);
		return ;
	}
	game->map = create_map(level);
	calc_bricks_f(game->map, game->map->bricks, game->map->nb_bricks);
	center_bar(game);
	spawn_ball(game);
}

char		*get_level(char *path, int lv)
{
	DIR			*dir;
	t_dirent	*fr;
	char		*ret;
	int			i;

	i = 0;
	dir = opendir(path);
	fr = readdir(dir);
	while (fr && fr->d_name[0] == '.')
		fr = readdir(dir);
	if (!fr)
		no_levels();
	while (i < lv)
	{
		fr = readdir(dir);
		i++;
		if (fr == NULL)
			return (NULL);
	}
	ret = ft_strjoin(path, fr->d_name);
	return (ret);
}
