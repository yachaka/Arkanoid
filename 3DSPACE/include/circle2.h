/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 14:28:23 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/03 14:46:04 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CIRCLE2_H
# define CIRCLE2_H

# include <stdlib.h>

typedef struct			s_circle2
{
	double				x;
	double				y;
	double				r;
}						t_circle2;

t_circle2				*new_circle2(double x, double y, double r);
void					fill_circle2(t_circle2 *circle2, double x, double y,
						double r);

#endif
