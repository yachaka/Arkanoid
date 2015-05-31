/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brick.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 16:01:43 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/03 23:23:48 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void			brick_got_hit(t_brick *brick, t_game *game)
{
	if (brick->type == BRICK_UNDESTRUCTIBLE)
		return ;
	brick->resistance -= 1;
	if (brick->resistance == 0)
		brick->destructed = 1;
	game->score += 1;
}

void			calc_bricks_f(t_map *map, t_brick *bricks, int n)
{
	int i;

	i = -1;
	while (++i < n)
	{
		bricks[i].x_in_f = -1.0f + (bricks[i].x * map->col_in_f);
		bricks[i].y_in_f = 1.0f - (bricks[i].y * map->row_in_f);
		bricks[i].w_in_f = bricks[i].width * map->col_in_f;
		bricks[i].h_in_f = bricks[i].height * map->row_in_f;
	}
}

t_brick			new_brick(int x, int y, int width, int height)
{
	t_brick brick;

	brick.x = x;
	brick.y = y;
	brick.width = width;
	brick.height = height;
	return (brick);
}

static char		brick_hit_at_more(t_segment2 v, t_ball *ball, t_brick *b)
{
	t_segment2 s1;

	if (ball->v->x < 0.0f && ball->v->y < 0.0f)
	{
		s1 = fill_segment2(b->x_in_f + b->w_in_f, b->y_in_f, b->x_in_f +
			b->w_in_f, b->y_in_f - b->h_in_f);
		if (intersection_segment2_to_segment2(&v, &s1))
			return (HIT_LEFT);
		else
			return (HIT_BOTTOM);
	}
	else
	{
		s1 = fill_segment2(b->x_in_f, b->y_in_f, b->x_in_f,
			b->y_in_f - b->h_in_f);
		if (intersection_segment2_to_segment2(&v, &s1))
			return (HIT_RIGHT);
		else
			return (HIT_BOTTOM);
	}
}

char			brick_hit_at(t_ball *ball, t_brick *b)
{
	t_segment2 v;
	t_segment2 s1;

	v = fill_segment2(ball->x - ball->v->x, ball->y - ball->v->y, ball->x,
		ball->y);
	if (ball->v->x >= 0.0f && ball->v->y >= 0.0f)
	{
		s1 = fill_segment2(b->x_in_f, b->y_in_f, b->x_in_f,
			b->y_in_f - b->h_in_f);
		if (intersection_segment2_to_segment2(&v, &s1))
			return (HIT_RIGHT);
		else
			return (HIT_TOP);
	}
	else if (ball->v->x < 0.0f && ball->v->y >= 0.0f)
	{
		s1 = fill_segment2(b->x_in_f + b->w_in_f, b->y_in_f, b->x_in_f +
			b->w_in_f, b->y_in_f - b->h_in_f);
		if (intersection_segment2_to_segment2(&v, &s1))
			return (HIT_LEFT);
		else
			return (HIT_TOP);
	}
	else
		return (brick_hit_at_more(v, ball, b));
}
