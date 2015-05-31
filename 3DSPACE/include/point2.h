/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 07:40:01 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/03 15:16:26 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT2_H
# define POINT2_H

# include <math.h>
# include <stdlib.h>

typedef struct				s_point2
{
	double					x;
	double					y;
}							t_point2;

t_point2					*new_point2(double x, double y);
void						fill_point2(t_point2 *p, double x, double y);
void						copy_point2_to_point2(t_point2 *dst,
							t_point2 *src);

int							equal_point2(t_point2 *p1, t_point2 *p2);
double						distance_point2(t_point2 *p1, t_point2 *p2);

#endif
