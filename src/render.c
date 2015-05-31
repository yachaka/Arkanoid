/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 16:43:17 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/10 10:49:52 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void			render(t_game *game)
{
	int			i;
	t_map		*map;

	map = game->map;
	i = -1;
	while (++i < map->nb_bricks)
		if (map->bricks[i].destructed == 0)
			render_brick(map->bricks + i);
	render_bar(game->bar, game->settings);
	render_ball(game->ball);
	print_text(ft_itoa(game->score), 0.90f, 0.90f);
	print_text("Score: ", 0.80f, 0.80f);
	print_text(ft_itoa(game->lives), 0.90f, -0.90f);
	print_text("Lives: ", 0.80f, -0.80f);
}

void			render_brick(t_brick *brick)
{
	if (brick->type == BRICK_UNDESTRUCTIBLE)
		glColor3ub(LIGHT_BLUE);
	else if (brick->resistance == 1)
		glColor3ub(YELLOW);
	else if (brick->resistance == 2)
		glColor3ub(ORANGE);
	else if (brick->resistance == 3)
		glColor3ub(RED);
	glBegin(GL_QUADS);
	glVertex2f(brick->x_in_f, brick->y_in_f);
	glVertex2f(brick->x_in_f + brick->w_in_f, brick->y_in_f);
	glVertex2f(brick->x_in_f + brick->w_in_f, brick->y_in_f - brick->h_in_f);
	glVertex2f(brick->x_in_f, brick->y_in_f - brick->h_in_f);
	glEnd();
}

void			render_ball(t_ball *ball)
{
	glColor3f(255.0f, 0.0f, 0.0f);
	gl_circle(ball->x, ball->y, ball->r, 500);
}

void			render_bar(t_bar *bar, t_settings *s)
{
	glColor3f(0.0f, 0.0f, 255.f);
	glBegin(GL_QUADS);
	glVertex2f(bar->x, s->bar_y);
	glVertex2f(bar->x + bar->width, s->bar_y);
	glVertex2f(bar->x + bar->width, s->bar_y - s->bar_height);
	glVertex2f(bar->x, s->bar_y - s->bar_height);
	glEnd();
}
