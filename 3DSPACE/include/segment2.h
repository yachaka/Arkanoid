/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment2.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 07:42:25 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/07 03:06:07 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEGMENT2_H
# define SEGMENT2_H

# include <stdlib.h>
# include "point2.h"

typedef struct				s_segment2
{
	t_point2				points[2];
}							t_segment2;

t_segment2					*new_segment2(float x1, float y1, float x2,
							float y2);
t_segment2					fill_segment2(float x1, float y1, float x2,
							float y2);

#endif
