/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle2_to_aabb2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 14:49:56 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/07 03:09:16 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circle2_to_aabb2.h"

static char		proj_seg(t_circle2 *circle2, t_aabb2 *aabb2)
{
	t_sproj		v;
	double		s1;
	double		s2;

	v.acx = circle2->x - aabb2->x;
	v.acy = circle2->y - aabb2->y;
	v.abx = aabb2->x - aabb2->x;
	v.aby = (aabb2->y + aabb2->height) - aabb2->y;
	v.bcx = circle2->x - aabb2->x;
	v.bcy = circle2->y - (aabb2->y + aabb2->height);
	s1 = (v.acx * v.abx) + (v.acy * v.aby);
	s2 = (v.bcx * v.abx) + (v.bcy * v.aby);
	if (s1 * s2 <= 0)
		return (1);
	v.acx = circle2->x - aabb2->x;
	v.acy = circle2->y - aabb2->y;
	v.abx = (aabb2->x + aabb2->width) - aabb2->x;
	v.aby = aabb2->y - aabb2->y;
	v.bcx = circle2->x - (aabb2->x + aabb2->width);
	v.bcy = circle2->y - aabb2->y;
	s1 = (v.acx * v.abx) + (v.acy * v.aby);
	s2 = (v.bcx * v.abx) + (v.bcy * v.aby);
	if (s1 * s2 <= 0)
		return (1);
	return (0);
}

static char		collision_circle2_point(t_circle2 *circle2, double x, double y)
{
	double		r2;
	double		d2;

	r2 = circle2->r * circle2->r;
	d2 = (x - circle2->x) * (x - circle2->x) +
		(y - circle2->y) * (y - circle2->y);
	if (d2 > r2)
		return (0);
	else
		return (1);
}

char			intersection_circle2_to_aabb2(t_circle2 *circle2,
				t_aabb2 *aabb2)
{
	if ((aabb2->x >= circle2->x + circle2->r) ||
			(aabb2->x + aabb2->width <= circle2->x - circle2->r) ||
			(aabb2->y <= circle2->y - circle2->r) ||
			(aabb2->y - aabb2->height >= circle2->y + circle2->r))
		return (0);
	else if (collision_circle2_point(circle2, aabb2->x, aabb2->y) == 1
		|| collision_circle2_point(circle2, aabb2->x + aabb2->width,
			aabb2->y) == 1
		|| collision_circle2_point(circle2, aabb2->x + aabb2->width,
			aabb2->y + aabb2->height) == 1
		|| collision_circle2_point(circle2, aabb2->x,
			aabb2->y + aabb2->height) == 1)
		return (1);
	else if ((circle2->x >= aabb2->x) && (circle2->x < aabb2->x + aabb2->width)
		&& (circle2->y <= aabb2->y) && (circle2->y > aabb2->y + aabb2->height))
		return (1);
	else if ((proj_seg(circle2, aabb2)) == 1)
		return (1);
	return (0);
}
