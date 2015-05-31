/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aabb2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 14:32:00 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/07 03:14:33 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aabb2.h"

t_aabb2			*new_aabb2(double x, double y, double width, double height)
{
	t_aabb2		*aabb2;

	aabb2 = (t_aabb2*)malloc(sizeof(t_aabb2));
	aabb2->x = x;
	aabb2->y = y;
	aabb2->width = width;
	aabb2->height = height;
	return (aabb2);
}

void			fill_aabb2(t_aabb2 *aabb2, t_point2 *p, double width,
				double height)
{
	aabb2->x = p->x;
	aabb2->y = p->y;
	aabb2->width = width;
	aabb2->height = height;
}
