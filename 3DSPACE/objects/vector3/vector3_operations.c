/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 07:35:51 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/07 03:16:35 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"

void				cross_product_vector3(t_vector3 *v1, t_vector3 *v2,
					t_vector3 *normal)
{
	normal->x = v1->y * v2->z - v1->z * v2->y;
	normal->y = v1->z * v2->x - v1->x * v2->z;
	normal->z = v1->x * v2->y - v1->y * v2->x;
}

double				dot_product_vector3(t_vector3 *v1, t_vector3 *v2)
{
	return ((v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z));
}
