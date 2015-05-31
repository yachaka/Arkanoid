/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 07:35:51 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/07 03:16:09 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector2.h"

double				cross_product_vector2(t_vector2 *v1, t_vector2 *v2)
{
	return ((v1->x * v2->y) - (v1->y * v2->x));
}

double				dot_product_vector2(t_vector2 *v1, t_vector2 *v2)
{
	return ((v1->x * v2->x) + (v1->y * v2->y));
}

t_vector2			*perpendicular_vector2(t_vector2 *vector2)
{
	return (new_vector2(-vector2->y, vector2->x));
}
