/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 14:37:32 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/07 03:14:40 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circle2.h"

t_circle2			*new_circle2(double x, double y, double r)
{
	t_circle2		*circle2;

	circle2 = (t_circle2*)malloc(sizeof(t_circle2));
	circle2->x = x;
	circle2->y = y;
	circle2->r = r;
	return (circle2);
}

void				fill_circle2(t_circle2 *circle2, double x, double y,
					double r)
{
	circle2->x = x;
	circle2->y = y;
	circle2->r = r;
}
