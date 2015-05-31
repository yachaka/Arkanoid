/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 18:00:19 by aaudiber          #+#    #+#             */
/*   Updated: 2015/05/03 23:27:47 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void		print_text(char *s, float x, float y)
{
	int		i;

	i = 0;
	glColor3f(BLACK);
	glRasterPos2f(x, y);
	while (s[i] != '\0')
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s[i]);
		i++;
	}
}
