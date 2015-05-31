/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 07:31:46 by ihermell          #+#    #+#             */
/*   Updated: 2015/01/20 10:08:03 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR2_H
# define VECTOR2_H

# include <stdlib.h>
# include <math.h>
# include "point2.h"

typedef struct				s_vector2
{
	float					x;
	float					y;
}							t_vector2;

t_vector2					*new_vector2(float x, float y);
t_vector2					*new_vector2_from_point2(t_point2 *p1,
							t_point2 *p2);
void						fill_vector2(float x, float y, t_vector2 *vector2);
void						fill_vector2_from_point2(t_point2 *p1, t_point2 *p2,
							t_vector2 *vector2);
double						length_vector2(t_vector2 *vector2);

void						normalize_vector2(t_vector2 *vector2);

double						cross_product_vector2(t_vector2 *v1, t_vector2 *v2);
double						dot_product_vector2(t_vector2 *v1, t_vector2 *v2);
t_vector2					*perpendicular_vector2(t_vector2 *vector2);

#endif
