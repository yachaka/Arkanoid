/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 16:50:47 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/03 22:29:22 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "vector2.h"

# define BRICK_BASIC 0
# define BRICK_HARD 1
# define BRICK_UNDESTRUCTIBLE 2

# define HIT_LEFT		0
# define HIT_RIGHT		1
# define HIT_TOP		2
# define HIT_BOTTOM		3

typedef struct			s_input
{
	char				left;
	char				right;
}						t_input;

typedef	struct			s_settings
{
	float				bar_y;
	float				bar_height;
}						t_settings;

typedef struct			s_ball
{
	float				x;
	float				y;
	float				r;
	t_vector2			*v;
}						t_ball;

typedef struct			s_bar
{
	float				x;
	float				width;
}						t_bar;

typedef struct			s_brick
{
	int					type;
	char				destructible;
	int					resistance;
	int					x;
	int					y;
	int					width;
	int					height;
	float				x_in_f;
	float				y_in_f;
	float				w_in_f;
	float				h_in_f;
	char				destructed;
}						t_brick;

typedef struct			s_map
{
	int					width;
	int					height;
	float				col_in_f;
	float				row_in_f;
	t_brick				*bricks;
	int					nb_bricks;
}						t_map;

typedef struct			s_game
{
	char				paused;
	char				run;
	int					level;
	int					lives;
	int					score;
	char				ball_running;
	t_ball				*ball;
	t_bar				*bar;
	t_map				*map;
	t_settings			*settings;
	t_input				*input;
}						t_game;

#endif
