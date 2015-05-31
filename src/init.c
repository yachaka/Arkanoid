/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 23:40:32 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/03 22:47:55 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

t_env			*init_env(void)
{
	t_env *e;

	e = (t_env*)malloc(sizeof(t_env));
	ft_bzero(e, sizeof(t_env));
	return (e);
}

GLFWwindow		*init_glfw(int width, int height, const char *title)
{
	GLFWwindow *window;

	if (!glfwInit())
		exit(EXIT_FAILURE);
	glfwSetErrorCallback(&glfw_error_callback);
	window = glfwCreateWindow(width, height, title, NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	glfwSetKeyCallback(window, &glfw_key_callback);
	glfwSetCursorPosCallback(window, &glfw_mouse_move_callback);
	glfwSetMouseButtonCallback(window, &glfw_mouse_button_callback);
	return (window);
}

static void		init_ball_bar(t_game *game)
{
	game->ball = (t_ball*)malloc(sizeof(t_ball));
	game->ball->x = 0.2f;
	game->ball->y = 0.4f;
	game->ball->r = 0.02f;
	game->ball->v = new_vector2(0.02f, 0.03f);
	game->bar = (t_bar*)malloc(sizeof(t_bar));
	game->bar->x = -0.2f;
	game->bar->width = 0.4f;
}

t_game			*init_game(void)
{
	t_game		*game;

	game = (t_game*)malloc(sizeof(t_game));
	game->paused = 0;
	game->run = 1;
	game->level = 0;
	game->lives = 3;
	game->score = 0;
	init_ball_bar(game);
	game->settings = (t_settings*)malloc(sizeof(t_settings));
	game->settings->bar_y = -0.92f;
	game->settings->bar_height = 0.04f;
	game->input = (t_input*)malloc(sizeof(t_input));
	ft_bzero(game->input, sizeof(t_input));
	load_level(game);
	return (game);
}
