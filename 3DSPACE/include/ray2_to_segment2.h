/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray2_to_segment2.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 08:41:21 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/03 15:08:40 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY2_TO_SEGMENT2_H
# define RAY2_TO_SEGMENT2_H

# include "vector2.h"
# include "segment2.h"
# include "ray2.h"
# include "point2.h"

# define R				v[0]
# define S				v[1]
# define QP				v[2]

# define UNUMERATOR		d[0]
# define DENOMINATOR	d[1]
# define U				d[2]
# define T				d[3]

int						intersection_ray2_to_segment2(t_ray2 *ray,
						t_segment2 *seg, t_point2 *intersection);

#endif
