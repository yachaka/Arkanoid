/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle2_to_aabb2.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 15:08:50 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/07 03:10:34 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CIRCLE2_TO_AABB2_H
# define CIRCLE2_TO_AABB2_H

# include "circle2.h"
# include "aabb2.h"

typedef struct			s_sproj
{
	double				acx;
	double				acy;
	double				abx;
	double				aby;
	double				bcx;
	double				bcy;
}						t_sproj;

char					intersection_circle2_to_aabb2(t_circle2 *circle2,
						t_aabb2 *aabb2);

#endif
