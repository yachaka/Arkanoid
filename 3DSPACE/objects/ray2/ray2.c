/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 07:50:49 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/07 03:15:54 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray2.h"

t_ray2				*new_ray2(float x, float y, double angle)
{
	t_ray2			*ray;

	ray = (t_ray2*)malloc(sizeof(t_ray2));
	ray->origin.x = x;
	ray->origin.y = y;
	set_ray2_angle(angle, ray);
	return (ray);
}

void				fill_ray2(float x, float y, double angle, t_ray2 *ray)
{
	ray->origin.x = x;
	ray->origin.y = y;
	set_ray2_angle(angle, ray);
}

void				set_ray2_angle(double angle, t_ray2 *ray)
{
	ray->angle = angle;
	ray->cos = cos(D2R(angle));
	ray->sin = sin(D2R(angle));
}
