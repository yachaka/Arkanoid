/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray2_to_segment2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 08:19:29 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/07 03:12:55 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray2_to_segment2.h"

static int			ft_hack(t_ray2 *ray, t_segment2 *seg,
					t_point2 *intersection)
{
	if ((ray->origin.x >= seg->points[0].x && ray->origin.x <= seg->points[1].x)
		|| (ray->origin.x >= seg->points[1].x
			&& ray->origin.x <= seg->points[0].x))
	{
		copy_point2_to_point2(intersection, &ray->origin);
		return (1);
	}
	if ((ray->cos >= 0 && (seg->points[0].x >= ray->origin.x
			|| seg->points[1].x >= ray->origin.x))
		|| (ray->cos < 0 && (seg->points[0].x < ray->origin.x
			|| seg->points[1].x < ray->origin.x)))
	{
		if (distance_point2(&ray->origin, &seg->points[0])
			< distance_point2(&ray->origin, &seg->points[1]))
			copy_point2_to_point2(intersection, &seg->points[0]);
		else
			copy_point2_to_point2(intersection, &seg->points[1]);
		return (1);
	}
	return (0);
}

int					intersection_ray2_to_segment2(t_ray2 *ray,
					t_segment2 *seg, t_point2 *intersection)
{
	t_vector2		v[3];
	double			d[4];

	R.x = ray->cos;
	R.y = -ray->sin;
	fill_vector2_from_point2(&seg->points[0], &seg->points[1], &S);
	fill_vector2_from_point2(&ray->origin, &seg->points[0], &QP);
	UNUMERATOR = cross_product_vector2(&QP, &R);
	DENOMINATOR = cross_product_vector2(&R, &S);
	if (UNUMERATOR <= 0.0001 && UNUMERATOR >= -0.0001
		&& DENOMINATOR <= 0.0001 && DENOMINATOR >= -0.0001)
		return (ft_hack(ray, seg, intersection));
	if (DENOMINATOR == 0)
		return (0);
	U = UNUMERATOR / DENOMINATOR;
	T = cross_product_vector2(&QP, &S) / DENOMINATOR;
	if (T >= 0 && U >= 0 && U <= 1)
	{
		intersection->x = ray->origin.x + T * R.x;
		intersection->y = ray->origin.y + T * R.y;
		return (1);
	}
	return (0);
}
