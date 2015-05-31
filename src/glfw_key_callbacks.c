/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glfw_callbacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 23:39:12 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/03 23:30:42 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void			glfw_key_callback(GLFWwindow *window, int key, int scancode,
				int action, int mods)
{
	if (action == GLFW_PRESS)
		glfw_key_press_callback(window, key, scancode, mods);
	else if (action == GLFW_RELEASE)
		glfw_key_release_callback(window, key, scancode, mods);
}

void			glfw_key_press_callback(GLFWwindow *window, int key,
				int scancode, int mods)
{
	t_game		*game;

	game = (t_game*)glfwGetWindowUserPointer(window);
	if (key == GLFW_KEY_ESCAPE)
		glfwSetWindowShouldClose(window, GL_TRUE);
	else if (key == GLFW_KEY_LEFT)
		game->input->left = 1;
	else if (key == GLFW_KEY_RIGHT)
		game->input->right = 1;
	(void)scancode;
	(void)mods;
}

void			glfw_key_release_callback(GLFWwindow *window, int key,
				int scancode, int mods)
{
	t_game		*game;

	game = (t_game*)glfwGetWindowUserPointer(window);
	if (key == GLFW_KEY_P)
		game->paused = !game->paused;
	else if (key == GLFW_KEY_LEFT)
		game->input->left = 0;
	else if (key == GLFW_KEY_RIGHT)
		game->input->right = 0;
	(void)key;
	(void)window;
	(void)scancode;
	(void)mods;
}
