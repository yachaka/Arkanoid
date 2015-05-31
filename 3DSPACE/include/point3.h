/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point3.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 07:40:01 by ihermell          #+#    #+#             */
/*   Updated: 2015/02/03 05:05:44 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT3_H
# define POINT3_H

# include <math.h>
# include <stdlib.h>

typedef struct				s_point3
{
	double					x;
	double					y;
	double					z;
}							t_point3;

t_point3					*new_point3(double x, double y, double z);
void						copy_point3_to_point3(t_point3 *dst,
							t_point3 *src);

int							equals_point3(t_point3 *p1, t_point3 *p2);
double						distance_point3(t_point3 *p1, t_point3 *p2);

#endif
