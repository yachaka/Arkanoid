/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point2_comparisons.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 08:49:20 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/07 03:15:08 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "point2.h"

int				equal_points2(t_point2 *p1, t_point2 *p2)
{
	return (p1->x == p2->x && p1->y == p2->y);
}

double			distance_point2(t_point2 *p1, t_point2 *p2)
{
	return (sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2)));
}
