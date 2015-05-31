/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 15:50:26 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/10 10:52:20 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

static void		process_bar_collisions(t_game *game)
{
	if (collision_ball_to_bar(game->ball, game->bar, game->settings))
	{
		game->ball->y = game->settings->bar_y + game->ball->r;
		bounce_ball(HIT_BOTTOM, game->ball);
	}
}

void			process_collisions(t_game *game)
{
	process_screen_collisions(game);
	process_bar_collisions(game);
	process_bricks_collisions(game);
}

static void		ft_hack(t_ball *b, t_brick *brick, t_game *game, int hit)
{
	if (hit == HIT_LEFT)
		b->x = brick->x_in_f + brick->w_in_f + b->r;
	else if (hit == HIT_RIGHT)
		b->x = brick->x_in_f - b->r;
	else if (hit == HIT_TOP)
		b->y = brick->y_in_f - brick->h_in_f - b->r;
	else if (hit == HIT_BOTTOM)
		b->y = brick->y_in_f + b->r;
	brick_got_hit(brick, game);
	should_load_next_level(game);
}

void			process_bricks_collisions(t_game *game)
{
	int			i;
	char		hit;
	t_brick		*bricks;
	t_ball		*b;

	i = -1;
	bricks = game->map->bricks;
	b = game->ball;
	while (++i < game->map->nb_bricks)
	{
		if (game->map->bricks[i].destructed == 1)
			continue ;
		if (collision_ball_to_brick(b, bricks + i))
		{
			hit = brick_hit_at(b, bricks + i);
			ft_hack(b, bricks + i, game, hit);
			bounce_ball(hit, b);
			break ;
		}
	}
}

void			process_screen_collisions(t_game *game)
{
	if (game->ball->x - game->ball->r <= -1.0f)
	{
		game->ball->x = -1.0f + game->ball->r;
		bounce_ball(HIT_LEFT, game->ball);
	}
	else if (game->ball->x + game->ball->r >= 1.0f)
	{
		game->ball->x = 1.0f - game->ball->r;
		bounce_ball(HIT_RIGHT, game->ball);
	}
	if (game->ball->y + game->ball->r >= 1.0f)
	{
		game->ball->y = 1.0f - game->ball->r;
		bounce_ball(HIT_TOP, game->ball);
	}
	else if (game->ball->y - game->ball->r <= -1.0f)
		lose_life(game);
}
