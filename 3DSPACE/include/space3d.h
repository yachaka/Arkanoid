/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 17:48:16 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/03 20:14:31 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPACE3D_H
# define SPACE3D_H

# include "ray2.h"
# include "point2.h"
# include "point3.h"
# include "segment2.h"
# include "vector2.h"
# include "vector3.h"
# include "aabb2.h"
# include "circle2.h"

# include "ray2_to_segment2.h"
# include "circle2_to_aabb2.h"
# include "segment2_to_segment2.h"

double				true_angle(double angle);

#endif
