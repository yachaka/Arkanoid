/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glfw_mouse_callbacks.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 15:30:03 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/03 21:22:43 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void			glfw_mouse_button_callback(GLFWwindow *window, int button,
				int action, int mods)
{
	t_game		*game;
	double		x;
	double		y;

	glfwGetCursorPos(window, &x, &y);
	game = (t_game*)glfwGetWindowUserPointer(window);
	if (button == GLFW_MOUSE_BUTTON_LEFT)
		if (game->ball_running == 0)
			throw_ball(game, get_width_in_f(window, x),
				get_height_in_f(window, y));
	(void)action;
	(void)mods;
}

void			glfw_mouse_move_callback(GLFWwindow *window, double x, double y)
{
	int			w;
	int			h;
	t_game		*game;

	glfwGetFramebufferSize(window, &w, &h);
	game = (t_game*)glfwGetWindowUserPointer(window);
	if (game->ball_running == 1)
		move_bar(game, -1.0f + ((x / w) * 2.0f) - game->bar->width / 2);
	(void)y;
}
