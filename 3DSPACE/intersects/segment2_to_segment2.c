/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment2_to_segment2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 18:31:55 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/07 03:13:49 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "segment2_to_segment2.h"

char			intersection_segment2_to_segment2(t_segment2 *s1,
				t_segment2 *s2)
{
	t_vector2	d;
	t_vector2	e;
	double		denom;
	double		t;
	double		u;

	fill_vector2(s1->points[1].x - s1->points[0].x,
		s1->points[1].y - s1->points[0].y, &d);
	fill_vector2(s2->points[1].x - s2->points[0].x,
		s2->points[1].y - s2->points[0].y, &e);
	denom = d.x * e.y - d.y * e.x;
	if (denom == 0)
		return (-1);
	t = -(s1->points[0].x * e.y - s2->points[0].x * e.y - e.x *
		s1->points[0].y + e.x * s2->points[0].y) / denom;
	if (t < 0 || t >= 1)
		return (0);
	u = -(-d.x * s1->points[0].y + d.x * s2->points[0].y + d.y *
		s1->points[0].x - d.y * s2->points[0].x) / denom;
	if (u < 0 || u >= 1)
		return (0);
	return (1);
}
