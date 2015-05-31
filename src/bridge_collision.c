/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bridge_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 15:49:05 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/03 20:29:01 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

char			collision_ball_to_bar(t_ball *ball, t_bar *bar, t_settings *s)
{
	t_point2	p;
	t_aabb2		aabb2;
	t_circle2	circle2;

	fill_point2(&p, bar->x, s->bar_y);
	fill_aabb2(&aabb2, &p, bar->width, s->bar_height);
	fill_circle2(&circle2, ball->x, ball->y, ball->r);
	if (intersection_circle2_to_aabb2(&circle2, &aabb2))
		return (1);
	return (0);
}

char			collision_ball_to_brick(t_ball *ball, t_brick *brick)
{
	t_point2	p;
	t_aabb2		aabb2;
	t_circle2	circle2;

	fill_point2(&p, brick->x_in_f, brick->y_in_f);
	fill_aabb2(&aabb2, &p, brick->w_in_f, brick->h_in_f);
	fill_circle2(&circle2, ball->x, ball->y, ball->r);
	if (intersection_circle2_to_aabb2(&circle2, &aabb2))
		return (1);
	return (0);
}
