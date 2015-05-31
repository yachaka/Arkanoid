/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray2.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 07:51:00 by ihermell          #+#    #+#             */
/*   Updated: 2015/01/22 22:47:07 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY2_H
# define RAY2_H

# include <math.h>
# include "point2.h"

# define R2D(a)				(a * 57.295779513082)
# define D2R(a)				(a * 0.017453292519)

typedef struct				s_ray2
{
	t_point2				origin;
	double					angle;
	double					cos;
	double					sin;
}							t_ray2;

t_ray2						*new_ray2(float x, float y, double angle);
void						fill_ray2(float x, float y, double angle,
							t_ray2 *ray);
void						set_ray2_angle(double angle, t_ray2 *ray);

#endif
