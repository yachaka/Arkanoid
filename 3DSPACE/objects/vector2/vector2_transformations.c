/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2_transformations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 07:36:57 by ihermell          #+#    #+#             */
/*   Updated: 2015/01/20 09:52:47 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector2.h"

void				normalize_vector2(t_vector2 *vector2)
{
	double			length;

	length = length_vector2(vector2);
	vector2->x = vector2->x / length;
	vector2->y = vector2->y / length;
}
