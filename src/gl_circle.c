/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_circle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 17:57:31 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/03 20:11:03 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "arkanoid.h"

void			gl_circle(float x, float y, float r, int segments)
{
	int			i;
	float		t;

	i = -1;
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y);
	while (++i <= segments)
	{
		t = 2 * M_PI * (float)i / (float)segments;
		glVertex2f(x + sin(t) * r, y + cos(t) * r);
	}
	glEnd();
}
