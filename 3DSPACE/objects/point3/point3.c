/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 07:40:33 by ihermell          #+#    #+#             */
/*   Updated: 2015/02/03 05:04:28 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point3.h"

t_point3			*new_point3(double x, double y, double z)
{
	t_point3		*p3;

	p3 = (t_point3*)malloc(sizeof(t_point3));
	p3->x = x;
	p3->y = y;
	p3->z = z;
	return (p3);
}

void				copy_point3_to_point3(t_point3 *dst, t_point3 *src)
{
	dst->x = src->x;
	dst->y = src->y;
	dst->z = src->z;
}
