/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ball.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 13:57:37 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/03 21:51:16 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void			throw_ball(t_game *game, float x, float y)
{
	game->ball->v->x = (x - game->ball->x) / 50;
	game->ball->v->y = (y - game->ball->y) / 50;
	game->ball_running = 1;
}

void			spawn_ball(t_game *game)
{
	game->ball_running = 0;
	game->ball->x = game->bar->x + game->bar->width / 2;
	game->ball->y = game->settings->bar_y + game->ball->r;
}

void			move_ball(t_game *game)
{
	game->ball->x += game->ball->v->x;
	game->ball->y += game->ball->v->y;
}

void			bounce_ball(int hit, t_ball *ball)
{
	if (hit == HIT_LEFT || hit == HIT_RIGHT)
		ball->v->x = -ball->v->x;
	else if (hit == HIT_BOTTOM || hit == HIT_TOP)
		ball->v->y = -ball->v->y;
}
