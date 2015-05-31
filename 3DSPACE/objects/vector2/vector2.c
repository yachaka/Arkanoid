/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 07:36:15 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/03 18:50:17 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector2.h"

t_vector2			*new_vector2(float x, float y)
{
	t_vector2		*vector2;

	vector2 = (t_vector2*)malloc(sizeof(t_vector2));
	vector2->x = x;
	vector2->y = y;
	return (vector2);
}

t_vector2			*new_vector2_from_point2(t_point2 *p1, t_point2 *p2)
{
	t_vector2		*vector2;

	vector2 = (t_vector2*)malloc(sizeof(t_vector2));
	vector2->x = p2->x - p1->x;
	vector2->y = p2->y - p1->y;
	return (vector2);
}

void				fill_vector2(float x, float y, t_vector2 *vector2)
{
	vector2->x = x;
	vector2->y = y;
}

void				fill_vector2_from_point2(t_point2 *p1, t_point2 *p2,
					t_vector2 *vector2)
{
	vector2->x = p2->x - p1->x;
	vector2->y = p2->y - p1->y;
}

double				length_vector2(t_vector2 *vector2)
{
	return (sqrt(pow(vector2->x, 2) + pow(vector2->y, 2)));
}
