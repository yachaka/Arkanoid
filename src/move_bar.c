/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 18:28:38 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/03 22:05:50 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void			center_bar(t_game *game)
{
	game->bar->x = 0.0f - game->bar->width / 2;
}

void			move_bar(t_game *game, float x)
{
	if (x < -1.0f)
		x = -1.0f;
	if (x + game->bar->width > 1.0f)
		x = 1.0f - game->bar->width;
	game->bar->x = x;
}
