/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point3_comparisons.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 18:17:09 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/07 03:15:34 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "point3.h"

int				equals_point3(t_point3 *p1, t_point3 *p2)
{
	return (p1->x == p2->x && p1->y == p2->y && p1->z == p2->z);
}

double			distance_point3(t_point3 *p1, t_point3 *p2)
{
	return (sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2) +
	pow(p1->z - p2->z, 2)));
}
