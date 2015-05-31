/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 17:46:20 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/07 03:16:24 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"

t_vector3			*new_vector3(double x, double y, double z)
{
	t_vector3		*vector3;

	vector3 = (t_vector3*)malloc(sizeof(t_vector3));
	vector3->x = x;
	vector3->y = y;
	vector3->z = z;
	return (vector3);
}

t_vector3			*new_vector3_from_point3(t_point3 *p1, t_point3 *p2)
{
	t_vector3		*vector3;

	vector3 = (t_vector3*)malloc(sizeof(t_vector3));
	vector3->x = p2->x - p1->x;
	vector3->y = p2->y - p1->y;
	vector3->z = p2->z - p1->z;
	return (vector3);
}

void				fill_vector3(double x, double y, double z,
					t_vector3 *vector3)
{
	vector3->x = x;
	vector3->y = y;
	vector3->z = z;
}

void				fill_vector3_from_point3(t_point3 *p1, t_point3 *p2,
					t_vector3 *vector3)
{
	vector3->x = p2->x - p1->x;
	vector3->y = p2->y - p1->y;
	vector3->z = p2->z - p1->z;
}

double				length_vector3(t_vector3 *vector3)
{
	return (sqrt(pow(vector3->x, 2) + pow(vector3->y, 2) + pow(vector3->z, 2)));
}
