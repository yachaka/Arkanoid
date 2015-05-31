/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 21:01:41 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/03 21:16:57 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

float			get_height_in_f(GLFWwindow *window, double pixels)
{
	int			w;
	int			h;

	glfwGetFramebufferSize(window, &w, &h);
	return (1.0f - (pixels / h) * 2.0f);
}

float			get_width_in_f(GLFWwindow *window, double pixels)
{
	int			w;
	int			h;

	glfwGetFramebufferSize(window, &w, &h);
	return (-1.0f + (pixels / w) * 2.0f);
}
