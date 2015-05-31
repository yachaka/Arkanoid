/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 07:40:33 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/03 15:18:09 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point2.h"

t_point2			*new_point2(double x, double y)
{
	t_point2		*p2;

	p2 = (t_point2*)malloc(sizeof(t_point2));
	p2->x = x;
	p2->y = y;
	return (p2);
}

void				fill_point2(t_point2 *p, double x, double y)
{
	p->x = x;
	p->y = y;
}

void				copy_point2_to_point2(t_point2 *dst, t_point2 *src)
{
	dst->x = src->x;
	dst->y = src->y;
}
