/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 17:48:49 by ihermell          #+#    #+#             */
/*   Updated: 2015/02/03 05:02:41 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR3_H
# define VECTOR3_H

# include <stdlib.h>
# include <math.h>
# include "point3.h"

typedef struct				s_vector3
{
	double					x;
	double					y;
	double					z;
}							t_vector3;

t_vector3					*new_vector3(double x, double y, double z);
t_vector3					*new_vector3_from_point3(t_point3 *p1,
							t_point3 *p2);
void						fill_vector3(double x, double y, double z,
							t_vector3 *vector3);
void						fill_vector3_from_point3(t_point3 *p1, t_point3 *p2,
							t_vector3 *vector3);
double						length_vector3(t_vector3 *vector3);

void						cross_product_vector3(t_vector3 *v1, t_vector3 *v2,
							t_vector3 *normal);
double						dot_product_vector3(t_vector3 *v1, t_vector3 *v2);

#endif
