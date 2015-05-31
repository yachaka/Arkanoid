/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 22:44:19 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/03 23:07:48 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

int			main(void)
{
	t_env	*e;

	e = init_env();
	e->window = init_glfw(640, 640, "Kate upton <3");
	e->game = init_game();
	glfwSetWindowUserPointer(e->window, e->game);
	while (!glfwWindowShouldClose(e->window))
	{
		glfwGetFramebufferSize(e->window, &e->w_width, &e->w_height);
		glViewport(0, 0, e->w_width, e->w_height);
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(255.0f, 255.0f, 255.0f, 0.0f);
		if (!e->game->paused)
			process(e->game);
		if (e->game->run == 0)
			glfwSetWindowShouldClose(e->window, GL_TRUE);
		render(e->game);
		glfwSwapBuffers(e->window);
		glfwPollEvents();
	}
	glfwDestroyWindow(e->window);
	glfwTerminate();
	return (0);
}
