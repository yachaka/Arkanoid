/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aabb2.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 14:30:32 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/03 14:46:00 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AABB2_H
# define AABB2_H

# include <stdlib.h>
# include "point2.h"

typedef struct			s_aabb2
{
	double				x;
	double				y;
	double				width;
	double				height;
}						t_aabb2;

t_aabb2					*new_aabb2(double x, double y, double width,
						double height);
void					fill_aabb2(t_aabb2 *aabb2, t_point2 *p, double width,
						double height);

#endif
