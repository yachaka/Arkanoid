/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 07:46:20 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/03 19:09:20 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "segment2.h"

t_segment2			*new_segment2(float x1, float y1, float x2, float y2)
{
	t_segment2		*seg;

	seg = (t_segment2*)malloc(sizeof(t_segment2));
	seg->points[0].x = x1;
	seg->points[0].y = y1;
	seg->points[1].x = x2;
	seg->points[1].y = y2;
	return (seg);
}

t_segment2			fill_segment2(float x1, float y1, float x2, float y2)
{
	t_segment2		seg;

	seg.points[0].x = x1;
	seg.points[0].y = y1;
	seg.points[1].x = x2;
	seg.points[1].y = y2;
	return (seg);
}
